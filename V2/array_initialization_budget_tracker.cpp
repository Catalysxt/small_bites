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

int main () {
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
    
    std::array<double, 12> expenses {0.0};
    int selection {}; // Used for capturing user input
	float budgetGoal{};

    do {
        std::cout << "\n=== MONTHLY BUDGET TRACKER ===";
        std::cout << "\n--- Main Menu ---";
        std::cout << "\n1. Enter expenses for a month";
        std::cout << "\n2. View all monthly expenses";
        std::cout << "\n3. Calculate total yearly spend";
        std::cout << "\n4. Identify month with highest/lowest spending";
		std::cout << "\n5. Set budget goals";
		std::cout << "\n6. Compare against monthly budget";
		std::cout << "\n7. Exit \n";
		std::cin >> selection;

		switch (selection)
		{ 
			case 1:
				// Prompt user for month
				std::cout << "Please select your month as a number with 1 = January: ";
				int monthNumber;
				std::cin >> monthNumber;

				// Validate input
				if (monthNumber <1 || monthNumber > 12) {
					std::cout << "Please enter a valid month!\n";
					break;
				}

				// Prompt user for expense
				std::cout << "\nEnter expenses for " << months[monthNumber - 1] << ": $";
				double exp;
				std::cin >> exp;
				// Add expenses to the correct month
				expenses[monthNumber - 1] = exp;

				std::cout << "$ " << exp << " recorded for " << months[monthNumber - 1] << "!\n";
				break;
			
			case 2:
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
				break;
			
			case 3:
			{
				float sum {};
				for (std::size_t index = 0; index < months.size(); ++index) {
					sum += expenses[index];
				}
				std::cout << "Total annual spending: " << "$ "
						  << std::fixed << std::setprecision(2)
						  << sum << '\n';
				
	    		break;
			} 

			case 4:
			{
				// Identify month with highest and lowest spending
				float minExp {999999.99}; // A very large number
				float maxExp {};
				// std::size_t required so we can iterate through the array
				std::size_t monthMin = 0;
				std::size_t monthMax = 0;
				for (std::size_t index = 0; index < expenses.size(); ++index) {
					// Skip unpopulated months
					if (expenses[index] == 0.0) { continue; }
					// If we've identified a smaller expense
					if (expenses[index] < minExp) {
						minExp = expenses[index];
						monthMin = index; // Attach the month that links to this smallest expense
					}
					// If we've identified a larger expense
					if (expenses[index] > maxExp) {
						maxExp = expenses[index];
						monthMax = index;
					}
				}
				// Print results
				std::cout << "Highest spending month: " << months[monthMax]
						  << " : $" << std::fixed << std::setprecision(2) << maxExp << '\n';
				std::cout << "Lowest spending month:  " << months[monthMin]
						  << " : $" << std::fixed << std::setprecision(2) << minExp << '\n';
				
						  break;
			}
	
	     	case 5:
				std::cout << "Enter your monthly budget goal: ";
				std::cin >> budgetGoal;
				std::cout << "Budget goal set to $" << budgetGoal << " per month\n";

				break;
	
			case 6:
				// Validate if user entered budget goal. If not, exit
				if (budgetGoal == 0.0) {
					std::cout << "Please enter a budget goal (Option 5)\n";
					break;
				}

				std::cout << "\n--- BUDGET COMPARISON (Goal: $" << std::fixed << std::setprecision(2) 
              			<< budgetGoal << " per month) ---\n\n";

				for (std::size_t index = 0; index < months.size(); ++index) {
					 // Validate if month has a populated expense
					 if (expenses[index] == 0.0) {
						continue;
					 }
					 float difference = expenses[index] - budgetGoal;

					 std::cout << std::left << std::setw(12) << months[index]
					           << ": $" << expenses[index] << " spent ";
					 
					 if (difference > 0) {
						std::cout << "(UNDER budget by $" << std::fixed << std::setprecision(2) 
						          << -difference << ")" << '\n'; 
					 }
					 if (difference < 0) {
						std::cout << "OVER budget by $" << std::fixed << std::setprecision(2)
						          << difference << ")" << '\n'; 
					 }
					 else { std::cout << "Exactly on budget. Congratulations!\n"; }

				}
				break;

			default:
				std::cout << "Invalid selection! Try again\n\n";
		}
    } while (selection != 7);
	// Keep looping until exit is selected
}