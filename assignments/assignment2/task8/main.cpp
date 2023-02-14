#include <iostream>
#include <stack>

using namespace std;



void choose_even_number (int arr1[], int arr2[]) {
    int result[10] = {}, position = 0 , i = 0, j = 0, k = 0;
   

    while (arr1[i]) {
        if(arr1[i] % 2 == 0){
            result[position] = arr1[i];
            position ++;
        }
      i++;
    }
    
    while (arr2[j]) {
        if(arr2[j] % 2 == 0){
            result[position] = arr2[j];
            position ++;
        }
        j++;
    }

    while(result[k]){
        cout << result[k] << endl;
        k++;
    }

}

int main(){
    int arr1[3] = {1,2,3}, arr2[3] = {4,5,6};

    choose_even_number(arr1, arr2); 

    return 0;
}