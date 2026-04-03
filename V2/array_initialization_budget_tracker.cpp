//******************************************************************************
// Array Initialization - V2
//
// Context: I went overboard with V2, built a basic budget tracker.
//
// Description: This program allows the user to enter their expenses for a month.
// The program will perform various functionality.

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

#include <iostream>
#include <array>
#include <string_view>
#include <iomanip> // For std::left, std::setw()
#include <string> 


// Syntax is std::array<type, num of elements>
constexpr std::array<std::string_view, 12> months {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
}; 

constexpr std::string_view menu = R"(
=== MONTHLY BUDGET TRACKER ===
--- Main Menu ---"
1. Enter expenses for a month
2. View all monthly expenses
3. Calculate total yearly spend
4. Identify month with highest/lowest spending
5. Set budget goals
6. Compare against monthly budget
7. Exit
)";

// Forward declarations
void enterExpensesForMonth(std::array<double, 12>& expenses);
void viewMonthlyExpenses(std::array<double, 12>& expenses);
void calcAnnualSpend(std::array<double, 12>& expenses);
void calcMinMax(std::array<double, 12>& expenses);
double setBudgetGoal(double& budgetGoal);
void compareMonthlyBudget(double& budgetGoal, std::array<double, 12>& expenses, std::array<std::string_view, 12> months);

enum menuOptions
{
	kEnterExpenses = 1,
	kViewMonthlyExpenses,
	kAnnualSpend,
	kMinMax,
	kSetBudgetGoal,
	kCompareBudget,
	kEXIT = 7
};

int main () {    
    
    std::array<double, 12> expenses {};
    int selection {}; // Used for capturing user input
	double budgetGoal;

    do {
		std::cout << menu;
		std::cin >> selection;

		switch (selection)
		{ 
			case kEnterExpenses: enterExpensesForMonth(expenses); break;
			case kViewMonthlyExpenses: viewMonthlyExpenses(expenses); break;
			case kAnnualSpend: calcAnnualSpend(expenses); break;
			case kMinMax: calcMinMax(expenses); break;
	     	case kSetBudgetGoal: setBudgetGoal(budgetGoal); break;
			case kCompareBudget: compareMonthlyBudget(budgetGoal, expenses, months); break;

			default:
				std::cerr << "Invalid selection! Try again\n\n";
		}
    } while (selection != kEXIT);
	// Keep looping until exit is selected
}

// case 1
void enterExpensesForMonth(std::array<double, 12>& expenses) {
	std::cout << "Please select your month as a number with 1 = January: ";
	int monthNumber{};
	std::cin >> monthNumber;

	// Validate input
	if (monthNumber < 1 || monthNumber > 12) {
		std::cerr << "Please enter a valid month!\n";
		return;
	}

	std::cout << "\nEnter expenses for " << months[monthNumber - 1] << ": $";
	double exp{};
	std::cin >> exp;
	// Add expenses to the correct month
	expenses[monthNumber - 1] = exp;

	std::cout << "$" << exp << " recorded for " << months[monthNumber - 1] << "!\n";
}

// case 2
void viewMonthlyExpenses(std::array<double, 12>& expenses) {
	std::cout << "MONTHLY EXPENSES\n";
	// Formating 
	std::cout << std::left << std::setw(12) << "Month" << "Amount\n";
	// A partition for clarity 
	std::cout << std::string(25, '-') << '\n';

	for (std::size_t index = 0; index < months.size(); ++index) {
	std::cout << std::left
				<< std::setw(12)
				<< months[index]
				<< ": " << "$"
				<< std::fixed 
				<< std::setprecision(2)
				<< expenses[index] << '\n';
	}
	// A partition for clarity 
	std::cout << std::string(25, '-') << '\n';
}

// case 3
void calcAnnualSpend(std::array<double, 12>& expenses) {	
	double sum {};
	for (std::size_t index = 0; index < expenses.size(); ++index) {
		sum += expenses[index];
	}
	std::cout << "Total annual spending: " << "$ "
	<< std::fixed << std::setprecision(2)
	<< sum << '\n';
}

// case 4
void calcMinMax(std::array<double, 12>& expenses) {
    // Identify month with highest and lowest spending
	double minExpense {999999.99}; // A very large number
	double maxExpense {};

	// std::size_t required so we can iterate through the array
	std::size_t monthMin = 0;
	std::size_t monthMax = 0;
	for (std::size_t index = 0; index < expenses.size(); ++index) {

		// Skip unpopulated months
		if (expenses[index] == 0.0) { continue; }

		// If we've identified a smaller expense
		if (expenses[index] < minExpense) {
			minExpense = expenses[index];
			monthMin = index; // Attach the month that links to this smallest expense
		}

		// If we've identified a larger expense
		if (expenses[index] > maxExpense) {
			maxExpense = expenses[index];
			monthMax = index;
		}
	}

	// Print results
	std::cout << "Highest spending month: " << months[monthMax]
				<< " : $" << std::fixed << std::setprecision(2) << maxExpense << '\n';
	std::cout << "Lowest spending month:  " << months[monthMin]
				<< " : $" << std::fixed << std::setprecision(2) << minExpense << '\n';
}

double setBudgetGoal(double& budgetGoal) {
	std::cout << "Enter your monthly budget goal: ";
	std::cin >> budgetGoal;
	std::cout << "Budget goal set to $" << budgetGoal << " per month\n";
	return budgetGoal;
}

void compareMonthlyBudget(double& budgetGoal, std::array<double, 12>& expenses, std::array<std::string_view, 12> months) {
	// Validate if user entered budget goal. If not, early return
	if (budgetGoal == 0.0) {
		std::cerr << "Please enter a budget goal (Option 5)\n";
		return;
	}

	std::cout << "\n--- BUDGET COMPARISON (Goal: $" << std::fixed << std::setprecision(2) 
			<< budgetGoal << " per month) ---\n\n";

	for (std::size_t index = 0; index < months.size(); ++index) {
			// Validate if month has a populated expense
			if (expenses[index] == 0.0) {
			continue;
			}
			double difference = expenses[index] - budgetGoal;

			std::cout << std::left << std::setw(12) << months[index]
					<< ": $" << expenses[index] << " spent ";
			
			if (difference > 0) {
			std::cout << "(UNDER budget by $" << std::fixed << std::setprecision(2) 
						<< -difference << ")" << '\n'; 
			}

			else if (difference < 0) {
			std::cout << "(OVER budget by $" << std::fixed << std::setprecision(2)
						<< difference << ")" << '\n'; 
			}

			else { std::cout << "Exactly on budget. Congratulations!\n"; }

	}
}
