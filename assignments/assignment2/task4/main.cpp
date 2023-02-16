#include <iostream>

using namespace std;

int main (){
    int input [7];

    cout << "Enter your inputs in number" << endl;

    for(int i = 0; i < 7; i++){
        cin >> input[i];
    }

    cout << "Your Output is" << endl << "[ ";

    for(int x:input){
        cout << "'" << x * x << "', ";
    }

    cout << "]" << endl;

    return 0;
}