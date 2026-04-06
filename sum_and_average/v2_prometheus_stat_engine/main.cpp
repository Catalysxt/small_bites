//******************************************************************************
// Prometheus Statistical Engine (V2)
//
// Description: A modular, high-performance processing engine.
// It utilizes the Strategy Pattern to perform various statistical analyses
// on user-provided datasets. 
//******************************************************************************

#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr()
#include <numeric> // For std::accumulate()
#include <algorithm> // For std::sort()
#include <cmath> // For std::sqrt(), std::setpow()
#include <concepts> // For std::floating_point
#include <expected> // For std::expected()
#include <format> // For std::format()
#include <string>

namespace Prometheus {


    template<typename T>
    concept Numeric = std::floating_point<T> || std::integral<T>;

    // Error list
    enum class EngineError {
        EmptyDataSet,
        InvalidInput,
        CalculationOverflow
    };

    // Strategy Pattern
    template<Numeric T>
    class IStatStrategy {
        public:
            virtual ~IStatStrategy() = default;

            [[nodiscard]] virtual std::expected<double, EngineError> 
            calculate(const std::vector<T>& data) const = 0;

            [[nodiscard]] virtual std::string getName() const = 0;
    };

    // Concrete strategies
    template<Numeric T>
    class MeanStrategy : public IStatStrategy<T> {
        public:
            [[nodiscard]] std::expected<double, EngineError>
            calculate(const std::vector<T>& data) const override {
                if (data.empty()) return std::unexpected(EngineError::EmptyDataSet);

                const double sum = std::accumulate(data.begin(), data.end(), 0.0);
                return sum / static_cast<double>(data.size());
            }

            [[nodiscard]] std::string getName() const {return "Arithmetic Mean";}
    };

    template<Numeric T>
    class MedianStrategy : public IStatStrategy<T> {
        public:
            [[nodiscard]] std::expected<double, EngineError>
            calculate(const std::vector<T>& data) const override {
                if (data.empty()) return std::unexpected(EngineError::EmptyDataSet);

                std::vector<T> sortedData = data;
                std::sort(sortedData.begin(), sortedData.end());

                const size_t size = sortedData.size();
                if (size % 2 == 0) {
                    return (static_cast<double>(sortedData[size / 2 - 1]) + 
                    static_cast<double>(sortedData[size / 2]) ) / 2.0;
                }

                return static_cast<double>(sortedData[size / 2]);
            };

            [[nodiscard]] std::string getName() const {return "Median Value";}
        };
    
    template<Numeric T>
    class StdDevStrategy : public IStatStrategy<T> {
    public:
        [[nodiscard]] std::expected<double, EngineError> 
        calculate(const std::vector<T>& data) const override {
            if (data.empty()) return std::unexpected(EngineError::EmptyDataSet);
            
            MeanStrategy<T> meanCalc;
            auto meanResult = meanCalc.calculate(data);
            
            double mean = *meanResult;
            double sq_sum = std::accumulate(data.begin(), data.end(), 0.0, 
                [mean](double acc, T val) {
                    return acc + std::pow(static_cast<double>(val) - mean, 2);
                });
            
            return std::sqrt(sq_sum / static_cast<double>(data.size()));
        }
        [[nodiscard]] std::string getName() const override { return "Standard Deviation"; }
    };

    // The Main Engine
    template<Numeric T>
    class StatisticalEngine
    {
        private:
            std::vector<T> m_dataRegistry;
            std::unique_ptr<IStatStrategy<T>> m_activeStrat;
        
        public:
            void ingestData(T value) {
                m_dataRegistry.push_back(value);
            }

            void setStrat(std::unique_ptr<IStatStrategy<T>> strat) {
                m_activeStrat = std::move(strat);
            }

            void runAnalysis() const {
                if (!m_activeStrat) {
                    std::cerr << "Error! No strategy set\n";
                    return;
                }

                auto result = m_activeStrat->calculate(m_dataRegistry);

                if (result) {
                    std::cout << std::format("[{}] Result: {:.4f}\n", m_activeStrat->getName(), result.value());
                    // .value()?
                }
                else {
                    handleError(result.error());
                }
            }
        private:
            void handleError(EngineError err) const {
                if (err == EngineError::EmptyDataSet) {
                    std::cerr << "Error! Dataset is empty\n";
                }
            }
    };

}

int main() {
    using namespace Prometheus;

    StatisticalEngine<double> engine;

    int count;
    std::cout << "Prometheus V2 | Statistical Engine\n";
    std::cout << "Enter number of elements: ";

    if (!(std::cin >> count || count <= 0)) {
        std::cerr << "Invalid count!\n";
        return 1;
    };

    // Populate engine
    for (int i = 0; i < count; ++i) {
        double val{};
        std::cout << std::format("{}. Enter Number: ", i + 1);
        if (std::cin >> val) {
            engine.ingestData(val);
        }
    }

    std::cout << "\nAnalysis: \n";

    engine.setStrat(std::make_unique<MeanStrategy<double>>());
    engine.runAnalysis();

    engine.setStrat(std::make_unique<MedianStrategy<double>>());
    engine.runAnalysis();

    engine.setStrat(std::make_unique<StdDevStrategy<double>>());
    engine.runAnalysis();
}

// Output
// Enter number of elements: 5
// 1. Enter Number: 12.2
// 2. Enter Number: 543
// 3. Enter Number: 12.2
// 4. Enter Number: 65
// 5. Enter Number: 34.66

// Analysis:
// [Arithmetic Mean] Result: 133.4120
// [Median Value] Result: 34.6600
// [Standard Deviation] Result: 205.7081
