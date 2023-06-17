// array_operations.cpp (implementation file)
//(implementation file)
#include "array_operations.h"
using namespace std;

void ArrayOperations::readDataFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        int value;
        while (file >> value) {
            arrayData.push_back({ value });// Add a new row with the first value
            for (int i = 1; i < 10; ++i) {
                file >> value;// Read the remaining 9 values for the row
                arrayData.back().push_back(value);
            }
        }
        file.close();
    }
    else {
        cout << "Unable to open the file.\n";
    }
}
//Check if a certain integer exists in the array
int ArrayOperations::searchElement(int value) {
    for (int i = 0; i < arrayData.size(); ++i) {
        for (int j = 0; j < arrayData[i].size(); ++j) {
            if (arrayData[i][j] == value) {
                return i * 10 + j;  // return the linear index
            }
        }
    }
    return -1;  // value not found
}

int ArrayOperations::modifyElement(int index, int newValue) {
    int row = index / 10;
    int col = index % 10;
    int oldValue = arrayData[row][col];
    arrayData[row][col] = newValue;
    return oldValue;
}

void ArrayOperations::addElement(int value) {
    int row = arrayData.size() - 1;
    int col = arrayData.back().size();
    if (col == 10) {
        arrayData.push_back({ value });
    }
    else {
        arrayData[row].push_back(value);
    }
}

void ArrayOperations::replaceElement(int index, int newValue) {
    int row = index / 10;
    int col = index % 10;
    arrayData[row][col] = newValue;
}

void ArrayOperations::removeElement(int index) {
    int row = index / 10;
    int col = index % 10;
    arrayData[row].erase(arrayData[row].begin() + col);
}

void ArrayOperations::printArray() {
    for (const auto& row : arrayData) {
        for (int value : row) {
            std::cout << value << " ";
        }
        cout << endl;
    }
}
