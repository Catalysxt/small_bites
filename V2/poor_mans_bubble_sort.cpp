//******************************************************************************
// Poor man's bubble sort - V2

// Description: Let's apply a variation of bubble sort to a real-life application
// This program is a basic encryptor

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************

#include <iostream>
#include <string>

// Forward Declaration
std::string GetUserInput();
std::string SwapInput(std::string str);


int main() {
    std::string input { GetUserInput() };
    std::string inputSwapped { SwapInput(input) };
    std::cout << "Your message encryped is: " << inputSwapped << '\n';

}

std::string GetUserInput() {
    std::cout << "Enter a message to encrypt: " << std::flush;
    std::string input;
    // Use std::ws to skip whitespace
    std::getline(std::cin >> std::ws, input);
    return input;
}

std::string SwapInput(std::string str) {
    for (int i = 0; i +1 < str.size(); i += 2) {
        // Use st::swap to make our life easier
        std::swap(str[i], str[i+1]);
    }
    return str;
}

//******************************************************************************
// Output

// Enter a message to encrypt: my favourite colour is blue
// Your message encryped is: ymf vauoiretc louo rsib ule

//******************************************************************************
