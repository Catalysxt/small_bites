//******************************************************************************
// Contact Manager - V2
//
// Description: Sorting ints, floats, doubles is boring. Let's sort a program-
// defined type. This program add contacts then applies different sorting
// algorithms can be applied

//******************************************************************************

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::sort
#include <iomanip> // std::setw(), std::left()
#include <memory> // std;:unique_ptr
#include <chrono> // std::chrono

// EVERYTHING is encapsulated in this namespace
namespace iam::contacts
{
    // This struct represents the contact object
    struct Contact
    {
        std::string firstName;
        std::string lastName;
        int age;

        // Use explicit to prevent implicit conversions
        Contact(std::string f, std::string l, int a) : firstName(std::move(f)), 
        lastName(std::move(l)), age(a) {}
    };

    // The ISortStrategy is one input into the sorting strategy however, it's also
    // decoupled from the sorting logic. This makes the program modular
    // Strategy Pattern: The ABC
    class ISortStrategy {
        public:
            virtual ~ISortStrategy() = default;
            virtual bool compare(const Contact& a, const Contact& b) const = 0;
    };

    // Strategy Pattern: The Concrete Classes

    class SortByLastName : public ISortStrategy {
        public:
        // [[nodiscard]] ??
        [[nodiscard]] bool compare(const Contact& a, const Contact& b) const override {
            return a.firstName < a.lastName;
        }
    };

    class SortByAge : public ISortStrategy {
        public:
        [[nodiscard]] bool compare(const Contact& a, const Contact& b) const override {
            return a.age < b.age; 
        }
    };

    // The Contact Manager
    // Is the high-level overseer. Creates and manages the interface
    // for performing operations
    class ContactManager
    {
        public:
            void addContact(Contact contact) {
                contacts.push_back(std::move(contact));
                // Move semantics via std::move()
            }
            // Use lamda expression to apply specific sorting algorithm
            void sortContacts(const ISortStrategy& strat) {
                std::sort(contacts.begin(), contacts.end(), 
                [&strat](const Contact& a, const Contact& b) {
                    return strat.compare(a, b); } );
            }
            void display(const std::string& title) {
                // For a pretty facade
                std::cout << "\n--- " << title << " ---\n";
                std::cout << std::left << std::setw(15) << "First"
                << std::setw(15) << "Last" 
                << "Age\n";

                // Display elements
                for (const auto& c : contacts) {
                    std::cout << std::left << std::setw(15) << c.firstName
                    << std::setw(15) << c.lastName
                    << c.age << "\n";
                }
            }
        private: 
            std::vector<Contact> contacts;
    };
};

int main() {
    using namespace iam::contacts;

    ContactManager manager;

    // Use struct list/brace initialization
    manager.addContact( {"Ben", "Donald", 34} );
    manager.addContact( {"Michael", "Robbins", 25} );
    manager.addContact( {"Ada", "Lovelace", 36} );
    manager.addContact( {"Linus", "Torvalds", 54} );

    manager.display("Unsorted Contacts");

    SortByLastName nameStrategy{};
    manager.sortContacts(nameStrategy);
    manager.display("Sorted by Last Name (Alphabetical)");

    // Let's sort by youngest age
    SortByAge ageStrat{};
    manager.sortContacts(ageStrat);
    manager.display("Sorted by Aged (Youngest First)");

}

// Output
// --- Unsorted Contacts ---
// First          Last           Age
// Ben            Donald         34
// Michael        Robbins        25
// Ada            Lovelace       36
// Linus          Torvalds       54

// --- Sorted by Last Name (Alphabetical) ---
// First          Last           Age
// Linus          Torvalds       54
// Ada            Lovelace       36
// Michael        Robbins        25
// Ben            Donald         34

// --- Sorted by Aged (Youngest First) ---
// First          Last           Age
// Michael        Robbins        25
// Ben            Donald         34
// Ada            Lovelace       36
// Linus          Torvalds       54
