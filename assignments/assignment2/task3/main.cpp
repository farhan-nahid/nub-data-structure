#include <iostream> 

using namespace std;

int main (){
    int input[5] = {};

    cout << "Enter your inputs in number" << endl;

    for(int i = 0; i < 5; i++){
        cin >> input[i];
    }

    cout << "Printing values from the array in reverse order:" << endl;

    for(int i = 4; i >= 0; i--){
       cout<< input[i] << endl;
    }


    return 0;
}