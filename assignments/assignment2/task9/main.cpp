#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input;
    vector<int> arr;

    // Read input string
    cout << "Enter a string of numbers separated by spaces: ";
    getline(cin, input);

    // Convert input string to array of integers
    stringstream ss(input);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }

    // Print original array
    cout << "Original array: [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Remove even numbers from array
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            arr.erase(arr.begin() + i);
            i--;
        }
    }

    // Print modified array
    cout << "Modified array: [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
