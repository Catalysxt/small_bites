//******************************************************************************
// Array Initialization - V1

// Description: This program will communicate various ways to initialize a
// C-style array. This is required before the array can be manipulated.

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

#include <iostream>

int main() {
	
	  // 1. List initialization 
    int days[] { 31, 23, 21, 31, 30, 12, 12, 29, 30, 31, 10, 15 };
   	// We can omit the length in []. The compiler will deduce it based on the 
		// initializer list
    
    // 2. Value initialization
    // Initialize an array of 15 ints with 0.
    int p1[15] {};
    
    std::cout << "Zero initialization: ";
    for (int i = 0; i < 15; ++i) {
        std::cout << p1[i] << ((i != 15-1) ? ", " : " ");
    }

    // 3. String initialization
    // We an initialize with a string literal!
    char greeting[] { "Hello World" };
    std::cout << "\nInitializing a string literal: " << greeting;
}

//******************************************************************************
// Output
// Zero initialization: 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 
// Initializing a string literal: Hello World
// 
//******************************************************************************
