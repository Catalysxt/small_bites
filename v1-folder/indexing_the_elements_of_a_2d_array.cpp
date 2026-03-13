//******************************************************************************
// Indexing the elements of a 2D array - V1
//
// Context: A two-dimensional array is an array of arrays, int arr1[x][y].
// The first index represents the rows, the second the columns.
// 2D arrays have many applications including: representing coordinate systems,
// developing the board/grid for Chess/Tic-Tac-Toe etc, matrix multiplication
// and image representation.
//

// Description: This program will initialize a 2D array and print out the elements
// at each index.

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

#include <iostream>

int main() {

    // Initialize an array with 5 rows and 2 columns
    int myArray[5][2] = {
        {1, 2}, // Row 0    [1][2]        
        {2, 4}, // Row 1    [2][4]
        {3, 6}, // Row 2    [3][6]
        {4, 8}, // Row 3    [4][8]
        {1, 4}, // Row 4    [1][4]
    };
    

    // Output all of the elements
    for (int i = 0; i < 5; ++i){ // Iterate through the rows
        for (int j = 0; j < 2; ++j) { // Iterate through the columns
            std::cout << "myArray[" << i << "][" << j << "]: "; // Display the location of an element
            std::cout << myArray[i][j] << '\n'; // Display the value of the element by indexing the array
        }
    }
}

//******************************************************************************
// Output

//    myArray[0][0]: 1
//    myArray[0][1]: 2
//    myArray[1][0]: 2
//    myArray[1][1]: 4
//    myArray[2][0]: 3
//    myArray[2][1]: 6
//    myArray[3][0]: 4
//    myArray[3][1]: 8
//    myArray[4][0]: 1
//    myArray[4][1]: 4
//******************************************************************************
