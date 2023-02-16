#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    int arr[7], max=0 , max_index = 0;

    cout << "Enter 7 numbers separated by commas: ";
    getline(cin, input);

    // Convert input string to array of integers
    int start = 0;
    int comma_pos = input.find(",");
    for (int i = 0; i < 7; i++) {
        string num_str = input.substr(start, comma_pos - start);
        arr[i] = stoi(num_str);
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
        start = comma_pos + 1;
        comma_pos = input.find(",", start);
        if (comma_pos == string::npos) {
            comma_pos = input.length();
        }
    }

    cout << "My Arr:[ ";
    for(auto x:arr){
        cout << x << ' ' ;
    }
    cout << "]" << endl;

    cout << "The largest number is " << max << " at index " << max_index << endl;
    return 0;
}
