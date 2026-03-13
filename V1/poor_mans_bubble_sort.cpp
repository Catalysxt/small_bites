//******************************************************************************
// Poor man's bubble sort - V1

// This program is a poor man’s implementation of bubble sort, which is a simple
// sorting algorithm. Despite having poor performance, it serves as a good
// introduction to algorithms.

// Description: The program initializes an array of 100 elements. It prompts the user
// for the size and array elements. Afterwards, the program displays the array
// contents before and after swapping.
// NOTE: This is not a full implementation of bubble sort. This is because the
// two elements are not compared and the array is only iterated once. 


//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

#include <iostream>

int main() {

    int myArray[100]; // Initialize array with 100 elements
    int temp;
    int size;
    
    std::cout << "Enter the array size: ";
    std::cin >> size;
    
    std::cout << "Enter the array elements: \n";
    for (int i = 0; i < size; ++i) { // Ensure the user doesn't exceed the array size
        std::cin >> myArray[i]; // Populate the array
    }
    
    std::cout << "The array before swapping: \n";
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << ", ";
    }
    
    // Swap the elements
    for (int i = 0; i < size - 1; i += 2) { // Swap every 2nd element
        temp = myArray[i];
        myArray[i] = myArray[i + 1]; // Swap element with the next position 
        myArray[i + 1] = temp; // Re-assign it
    }
    
    std::cout << "\nThe array after swapping: \n";
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << ", ";
    }
}


//******************************************************************************
// Output

// Enter the array size: 6
// Enter the array elements: 
// 3 44 2 43 71 3
// The array before swapping: 
// 3, 44, 2, 43, 71, 3, 
// The array after swapping: 
// 44, 3, 43, 2, 3, 71, 

//******************************************************************************