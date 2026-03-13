//******************************************************************************
// Indexing the elements of a 2D array - V2
//
// Context: This program is an expansion of V1. NOTE: std::vector is used rather
// than std::array since it's a dynamic container. The array contents isn't
// available at compile time.
//

// Description: This program will prompt the user for the rows and columns of a
// 2d array. After validating the user's input, the program will display the
// array of random values

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

#include <iostream>
#include <vector> // For std::vector()
#include <random> // For std::mt19937()
#include <utility> // For std::pair()
#include <iomanip> // For std::setw()
#include <limits> // For std::numeric_limits

// Forward Declarations
std::pair<int, int> GetUserInput() ;
void PopulateAndDisplay(std::vector<std::vector<int>>& arr2d);
void ignoreLine();

int main() {
    // Store row and col
    auto p1 { GetUserInput() };

    // Initialize a vector of size row where each row is another vector of col
    std::vector<std::vector<int>> arr1(p1.first, std::vector<int>(p1.second));
    
    PopulateAndDisplay(arr1);
}

// FYI: Could use a struct to store rows and columns
std::pair<int, int> GetUserInput() {
    // Validate input
    int row {};
    while (true) {
        std::cout << "Enter number of rows: ";

        // Validate input
        if (std::cin >> row && row > 0) {
            break; // Successful input
        }
        // Unsuccessful input
        else {
            std::cout << "Please enter a positive number!\n\n";
            std::cin.clear(); // Clear the buffer
            ignoreLine();
        }
            
    }

    int col;
    while (true) {
        std::cout << "Enter number of columns: ";

        // Validate input
        if (std::cin >> col && col > 0) {
            break; // Successful input
        }
        // Unsuccessful input
        else {
            std::cout << "Please enter a positive number!\n\n";
            std::cin.clear(); // Clear the buffer
            ignoreLine();
        }
            
    }

    return {row, col};
    /// Equivalent to return return std::pair<int, int>{row, col};
}

void PopulateAndDisplay(std::vector<std::vector<int>>& arr2d) {
    // RNG will be developed using mersenne twister

    // Seed the RNG engine 
    std::random_device rd;
    std::mt19937 gen(rd());

    // Shape the RNG engine (Feel free to modify the values)
    std::uniform_int_distribution<int> dist1(1, 99);

    // Iterate through vector and randomize elements
    for (auto& row : arr2d) {
        for (auto& val : row) {
            val = dist1(gen);
            std::cout << std::setw(4) << val << " ";
        }
        std::cout << '\n';
    }
}

// Cleanup for invalid input
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//******************************************************************************
// Output
//
// Enter number of rows: -11
// Please enter a positive number!

// Enter number of rows: 3
// Enter number of columns: 11
//   16   76   60   55   63   17   40   31   73   44    7 
//   16   19   86   21   53    3   51   23   34   82   63
//   48   79   87   22   68   34   32   70   48   27   69
//
//******************************************************************************
