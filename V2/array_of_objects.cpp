//******************************************************************************
// Array of objects - V2
// Restaurant Menu
//
// Description: An array of MenuItem objects stores all the possible products
// in a restaurant. It’s contents will be printed by overloading the insertion
// operator (<<). 

//  Ahmad Sarraj
//  Mar 2025
//******************************************************************************


#include <iostream>
#include <array>
#include <string> 
#include <iomanip>

class MenuItem
{
	public:
		MenuItem(std::string name, double cost) : m_name{name}, m_cost{cost} {}

		std::string getName() const { return m_name; }
		double getCost() const { return m_cost; }
	    void display() const {
        std::cout << m_name << " - $" << m_cost;
    	}

		friend std::ostream& operator<< (std::ostream& out, const MenuItem& item);

		private:
		std::string m_name {};
		double m_cost {};
	};
	
std::ostream& operator<< (std::ostream& out, const MenuItem& item) {
	out << item.m_name << " - $" << item.m_cost;
	// operator overloading cannot call method e.g. item.display()
	
	return out;
}

void welcome(const std::array<MenuItem, 7>& items);

int main() {

	// Instantiate array of 7 MenuItem objects
	std::array<MenuItem, 7> menuItems { {
		MenuItem("Wedges", 11.99),
		MenuItem("Cheeseburger", 14.99),
		MenuItem("Salmon", 34.99),
		MenuItem("Iced Coffee", 8.99),
		MenuItem("Pasta", 24.99),
		MenuItem("Pancakes", 16.99),
		MenuItem("Meatlovers", 22.99),
	} };

	welcome(menuItems);
}

void welcome(const std::array<MenuItem, 7>& items) {
	std::cout << "Welcome to the restaurant!\n";
	std::cout << "   Today's Menu Items:\n";
	std::cout << "--------------------------\n";
	for (const auto& item : items) {
		std::cout << std::left << std::setw(12) << item;
		std::cout << '\n';
	}
}

//******************************************************************************
// Output
// Welcome to the restaurant!
//    Today's Menu Items:
// --------------------------
// Wedges       - $11.99
// Cheeseburger - $14.99
// Salmon       - $34.99
// Iced Coffee  - $8.99
// Pasta        - $24.99
// Pancakes     - $16.99
// Meatlovers   - $22.99
//
//******************************************************************************
