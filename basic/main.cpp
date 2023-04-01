#include <iostream>

using namespace std;

int main (){
    int how_many_number = 0, arr[how_many_number];

    cout << "How many number you want?" << endl;

    cin >> how_many_number;

    for(int i =0; i < how_many_number; i++){
       cin >>  arr[i] ;
    }
    
    for(int i =0; i < how_many_number; i++){
       cout <<  arr[i] << " ";
    }

    cout << endl;

    return 0;

}