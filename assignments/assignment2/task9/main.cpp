// #include <iostream>
// #include <string.h>
// #include <vector>

// using namespace std;


// int convert_string_to_number(string input) {
//     // char *a = strtok(input, ',');
//     // string *token = strtok(input, "-");
//     return 0;
// }

// void string_splitter(string str, char separator){
//     vector <string> splittedString;
    
//     int start_index = 0, end_index = 0;
//     string temp;
//     for(int i = 0; i <= str.size(); i++){
//         if(str[i] == separator || i == str.size()){
//             end_index = i;
//             temp.append(str, start_index, end_index - start_index);
//             splittedString.push_back(temp);
//             start_index = end_index + 1;
//         }
//     }

//     for (string st: splittedString){
//         cout << st << endl;
//     }
//     // return "splittedString";
// } 


// int main () {
//     string input;
//     char separator = ',';
//     cin >> input;
    
//      string_splitter(input, separator);


//    int output = convert_string_to_number(input);

//     return 0;
// }


#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string input_str;
    cout << "Enter a string of numbers separated by spaces: ";
    getline(cin, input_str);

    stringstream ss(input_str);
    int num;
    int nums_arr[100]; // assuming no more than 100 numbers in the input string
    int nums_count = 0;

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
    int odd_count = 0;
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
