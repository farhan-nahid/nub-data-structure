#include <iostream>
#include <vector>

using namespace std;

int main (){

    vector <string> myStrs = {"hey", "there", " ", "what's", " ", "up" , "", "?"};
    vector <string> modifiedArray = {};

    for(int i =0; i<8; i++){
        if(myStrs[i] != "" && myStrs[i] != " "){
            modifiedArray.push_back(myStrs[i]);
        }
    }

    cout << "Original Array: [";

    for(const auto &x: myStrs){
        cout << "'" << x <<  "', ";
    }

    cout << " ]" << endl << "Modified Array: [";

    for(const auto &y: modifiedArray){
         cout << "'" << y <<  "', ";
    }

    cout  << " ]" << endl;

    return 0;
}