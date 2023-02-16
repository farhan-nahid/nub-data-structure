#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string input_str;
    cout << "Enter a string of numbers separated by spaces: ";
    int num, nums_arr[100], nums_count = 0, odd_count = 0;
    getline(cin, input_str);

    stringstream ss(input_str);
  

    // convert the input string to an array of numbers
    while (ss >> num) {
        nums_arr[nums_count] = num;
        nums_count++;
    }

    // print the original array of numbers
    cout << "Original array of numbers: ";
    for (int i = 0; i < nums_count; i++) {
        cout << nums_arr[i] << " ";
    }

    cout << endl;

    // remove even numbers from the array

    for (int i = 0; i < nums_count; i++) {
        if (nums_arr[i] % 2 != 0) {
            nums_arr[odd_count] = nums_arr[i];
            odd_count++;
        }
    }

    // print the modified array of numbers
    cout << "Modified array of numbers (even numbers removed): ";
    for (int i = 0; i < odd_count; i++) {
        cout << nums_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
