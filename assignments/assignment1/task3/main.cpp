#include <iostream>

using namespace std;

void delete_value(int arr[], int size, int index){  
    for(int i = index + 1; i <= size; i++){
         arr[i - 1] = arr[i];
    }
    
    for(int i = 0; i < size; i++){
         cout << arr[i] << endl;
    }
}


int main(){
    int arr[] = {1,2,3,4}, size = 4, index = 2;

    delete_value(arr, size, index);

    return 0;
}