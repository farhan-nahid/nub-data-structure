#include <iostream>

using namespace std;

void insert_value(int arr[], int size, int index, int value){
    for(int i = size; i >= index; i--){
        arr[i + 1] = arr[i];
    }

    arr[index] = value;
    
    for(int i = 0; i < size; i++){
        cout << arr[i] << endl;
    }

}


int main(){
    int arr[] = {1,2,4,5,6,7,8,9,10,0,0}, size = 11, index = 2, value = 3;

    insert_value(arr, size, index, value);

    return 0;
}