//******************************************************************************
// Contact Manager - V2
//
// Description: Add contacts then different sorting algorithms can be applied
// 
//******************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::sort
#include <iomanip> // std::setw(), std::left()
#include <memory> // std;:unique_ptr
#include <chrono> // std::chrono

// EVERYTHING is encapsulated in this namespace
namespace iam::contacts
{
    // This struct represents the contact object
    struct Contact
    {
        std::string firstName;
        std::string lastName;
        int age;
        std::chrono::system_clock::time_point dateAdded; // I think this is used for a sorting algo

        // Use explicit to prevent implicit conversions
        // std::move is used in initializer list
        explicit Contact(std::string f, std::string l, int a) : firstName(std::move(f)), 
        lastName(std::move(l)), age(a), dateAdded(std::chrono::system_clock::now()) {}
    };

    // The ISortStrategy is one input into the sorting strategy however, it's also
    // decoupled from the sorting logic. This makes the program modular
    // Strategy Pattern: The ABC
    class ISortStrategy {
        public:
            ~ISortStrategy();
            virtual bool compare(const Contact& a, const Contact& b) const = 0;
            // What's the "const = 0". Is this to facilitate the selection of no algorithm?
    };

    // Strategy Pattern: The Concrete Classes

    class SortByLastName : ISortStrategy {
        public:
        // [[nodiscard]] ??
        [[nodiscard]] bool compare(const Contact& a, const Contact& b) const override {
            return a.firstName < a.lastName;
        }
    };

    class SortByAge : ISortStrategy {
        public:
        [[nodiscard]] bool compare(const Contact& a, const Contact& b) const override {
            return a.age < b.age; 
        }
    };

    // The Contact Manager
    // Is the high-level overseer. Creates and manages the interface for performing operations
    class ContactManager
    {
        public:

        private: 
    };
};

int main() {
}
