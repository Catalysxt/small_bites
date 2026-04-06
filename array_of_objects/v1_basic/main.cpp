//******************************************************************************
// Array or Objects - V1

// Description: In addition to creating an array of fundamental types, we can
// create arrays of program-defined types. 
// This program implements a class, instantiates an array of class objects,
// assigns the objects then prints the array contents.

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

#include <iostream>

// Create a class
class Digit
{
    public:
        void setX(int i) { m_x = i; }
        int getX() { return m_x; }
    private:
        int m_x;
};

int main()
{
    // Instantiate an array of class objects
    Digit Arr[5];
    
    // Assign the elements
    for(int i = 0; i < 5; ++i) {
        Arr[i].setX(i);
    }
    
    // Display the elements
    for (int i = 0; i < 5; ++i) {
        std::cout << "Arr[" << i << "].getX(): " << 
        Arr[i].getX() << '\n';
    }
}

//******************************************************************************
// Output
// Arr[0].getX(): 0
// Arr[1].getX(): 1
// Arr[2].getX(): 2
// Arr[3].getX(): 3
// Arr[4].getX(): 4
// 
//******************************************************************************
