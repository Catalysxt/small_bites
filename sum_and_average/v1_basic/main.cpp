#include <iostream>

int main() {
    
    int length;
    float sum {0.0};
    float average;
    
    std::cout << "Enter the amount of elements: ";
    std::cin >> length;
    
    // Initialize array with user input
    float numbers[length];
    
    // Prompt user to initialize it
    for(int i = 0; i < length; ++i) {
        std::cout << i + 1 << ". " << "Enter number: ";
        std::cin >> numbers[i];
        sum += numbers[i]; // Develop the sum
    }
    
    std::cout << "Sum: " << sum;
    
    std::cout << " Average: " << (sum/length);
    
    return 0;
}

// terminal
// Enter the amount of elements: 5
// 1. Enter number: 3
// 2. Enter number: 2
// 3. Enter number: 5
// 4. Enter number: 3
// 5. Enter number: 7
// Sum: 20 Average: 4
