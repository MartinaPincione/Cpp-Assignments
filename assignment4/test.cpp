#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

stack<int> readIntegersFromFile() {
    // Define the stack to store integers
    stack<int> numbers;
    // Define the input file stream
    ifstream inputFile("nums.txt");

    // Check if the file was successfully opened
    if (!inputFile.is_open()) {
        cout << "Failed to open file." << endl;
        exit(1);
    }

    // Read integers from the file and push them onto the stack
    int number;
    while (inputFile >> number) {
        numbers.push(number);
    }

    // Close the file
    inputFile.close();

    return numbers;
}

int main() {
    stack<int> numbers = readIntegersFromFile();

    // Print the numbers on the stack
    while (!numbers.empty()) {
        cout << numbers.top() << endl;
        numbers.pop();
    }

    return 0;
}
