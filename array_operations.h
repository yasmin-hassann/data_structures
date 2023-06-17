
//header file
#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class ArrayOperations {
public:
    // Read data from a file into the 2D array
    void readDataFromFile(const string& filename);

    // Search for a value in the array 
    int searchElement(int value);
    // Modify the value at  index and return the old value
    int modifyElement(int index, int newValue);
    void addElement(int value);
    void replaceElement(int index, int newValue);
    void removeElement(int index);
    void printArray();

private:
    vector<vector<int>> arrayData;
};

#endif  

