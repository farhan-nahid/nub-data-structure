#include <iostream>
#include <array>

using namespace std;

int main () {
    int arr1[4] = {1,4,7,5};
    int arr2[4] = {6,1,3,9};

    int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
    int arr2_size = sizeof(arr2) / sizeof(arr2[0]);


    for(int i= 0; i < arr1_size; i++){
        arr1[arr1_size - 1 + i] = arr2[i];
    }

    cout << "[ ";
    for(int i=0; i < arr1_size + arr2_size -1; i++){
        cout << arr1[i] << ' ';
    }

    cout << " ]" << endl;

    return 0;
}