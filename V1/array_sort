//******************************************************************************
// Array Sort - V1
// 
// Context: An array contains a collection ints, floats, strings or custom-types.
// Often there is a need to sort the array. E.g. your contacts are ordered in
// alphabetical order and your emails are sorted from newest to oldest.
//
// Description: This program will initialize and print a random array unsorted
// ad then sorted from lowest to highest

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

#include <iostream>
#include <algorithm> // std::swap()

#define SIZE 10

int main() {

    std::cout << "Array values: " <<
    "12, 52, 34, 643, 2, 64, 32, 88, 9, 54" << '\n';
    
    // Initialize array
    int array[SIZE] = { 12, 52, 34, 643, 2, 64, 32, 88, 9, 54 };
    
    std::cout << "The array sorted: ";
    
    // Iterate through array
    for (int startIndex = 0; startIndex < SIZE; ++startIndex)
    {
        // smallestIndex is the ... smallest index
        int smallestIndex = startIndex;
        
        // Search for smallestIndex
        for (int nowIndex = startIndex + 1; nowIndex < SIZE; 
        ++nowIndex)
        {
            // If we've located a new smallest index
            if(array[nowIndex] < array[smallestIndex])
                smallestIndex = nowIndex; // Reassign variable
        }
        
    // Swap start element for new smallest element using std::swap()
    std::swap(array[startIndex], array[smallestIndex]);
    
    // Continue iterating through array
    }
    
    // Print the result
    for (int i = 0; i < SIZE; ++i)
        std::cout << array[i] << ( (i != SIZE-1) ? ", " : " ");
}

//******************************************************************************
// Output
// Array values: 12, 52, 34, 643, 2, 64, 32, 88, 9, 54
// The array sorted: 2, 9, 12, 32, 34, 52, 54, 64, 88, 643 

//******************************************************************************
