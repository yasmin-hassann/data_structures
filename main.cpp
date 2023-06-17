//https://www.programiz.com/cpp-programming/arrays --C++ Arrays
//https://www.geeksforgeeks.org/exception-handling-c/

#include <iostream>
#include "array_operations.h"
#include <limits>

using namespace std;

int main() {
    ArrayOperations arrayOps;
    arrayOps.readDataFromFile("data.txt"); // Read data from file into the array

    cout << "Array Data:\n";
    arrayOps.printArray(); // Print the array data
    cout << endl;

    int searchValue;
    bool validInput = false;
    while (!validInput) {
        try {
            cout << "Enter a value to search in the array: ";
            cin >> searchValue; // Get the value to search for
            cout << endl;

            int searchIndex = arrayOps.searchElement(searchValue); // Search for the value in the array
            if (searchIndex != -1) {
                cout << "Value " << searchValue << " found at index " << searchIndex << endl;
                validInput = true; // Break out of the loop if the input is valid
            }
            else {
                cout << "Value " << searchValue << " not found in the array.please try again..\n";
                cin >> searchValue;
            }

            validInput = true; // If no exception is thrown, the input is valid
        }
        catch (const std::exception& e) {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input
        }
    }
    cout << endl;

    int modifyIndex;
    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter an index to modify an element: ";
            cin >> modifyIndex; // Get the index to modify
            cout << endl;

            int modifyNewValue;
            cout << "Enter the new value: ";
            cin >> modifyNewValue; // Get the new value
            cout << endl;

            int oldValue = arrayOps.modifyElement(modifyIndex, modifyNewValue); // Modify the element at the given index
            cout << "Modified value at index " << modifyIndex << ". Old value: " << oldValue
                << ", New value: " << arrayOps.modifyElement(modifyIndex, modifyNewValue) << std::endl;

            validInput = true; // If no exception is thrown, the input is valid
        }
        catch (const std::exception& e) {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input
        }
    }
    cout << endl;

    int addValue;
    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter a value to add to the array: ";
            cin >> addValue; // Get the value to add
            cout << endl;

            arrayOps.addElement(addValue); // Add the value to the array
            cout << "Added value " << addValue << " to the array.\n";

            validInput = true; // If no exception is thrown, the input is valid
        }
        catch (const std::exception& e) {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input
        }
    }
    cout << endl;

    int replaceIndex;
    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter an index to replace an element: ";
            cin >> replaceIndex;
            cout << endl;
            int replaceValue;
            cout << "Enter the new value: ";
            cin >> replaceValue; // Get the new value
            cout << endl;

            arrayOps.replaceElement(replaceIndex, replaceValue); // Replace the element at the given index
            cout << "Replaced value at index " << replaceIndex << " with " << replaceValue << ".\n";

            validInput = true; // If no exception is thrown, the input is valid
        }
        catch (const std::exception& e) {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input
        }
    }
    cout << endl;

    int removeIndex;
    validInput = false;
    while (!validInput) {
        try {
            cout << "Enter an index to remove an element: ";
            cin >> removeIndex; // Get the index to remove
            cout << endl;

            arrayOps.removeElement(removeIndex); // Remove the element at the given index
            cout << "Removed value at index " << removeIndex << ".\n";

            validInput = true; // If no exception is thrown, the input is valid
        }
        catch (const std::exception& e) {
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear the error flags
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input
        }
    }
    cout << endl;

    cout << "Updated Array:\n";
    arrayOps.printArray(); // Print the updated array

    return 0;


}