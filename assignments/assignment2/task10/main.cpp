#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Enter a string of comma-separated numbers: ";
    getline(cin, input);
    
    // Create an array of integers from the input string
    const int MAX_SIZE = 100;
    int numbers[MAX_SIZE];
    int count = 0;
    string number = "";
    for (char c : input) {
        if (c == ',') {
            numbers[count] = stoi(number);
            count++;
            number = "";
        } else if (isdigit(c)) {
            number += c;
        }
    }
    // Add the last number to the array
    if (!number.empty()) {
        numbers[count] = stoi(number);
        count++;
    }
    
    // Print the input array
    cout << "Input array: [";
    for (int i = 0; i < count; i++) {
        cout << numbers[i];
        if (i != count - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    // Remove duplicates from the array
    int modified[MAX_SIZE];
    int modifiedCount = 0;
    for (int i = 0; i < count; i++) {
        bool duplicate = false;
        for (int j = 0; j < modifiedCount; j++) {
            if (numbers[i] == modified[j]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            modified[modifiedCount] = numbers[i];
            modifiedCount++;
        }
    }
    
    // Print the modified array
    cout << "Modified array: [";
    for (int i = 0; i < modifiedCount; i++) {
        cout << modified[i];
        if (i != modifiedCount - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    return 0;
}
