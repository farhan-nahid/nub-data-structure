#include <iostream>

using namespace std;

int main (){
    int input [7];

    for(int i =0; i<7;i++){
        cin >> input[i];
    }

    cout << "[ ";

    for(int x:input){
        cout << "'" << x * x << "', ";
    }

    cout << "]" << endl;

    return 0;
}