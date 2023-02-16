#include <iostream>
#include <stack>

using namespace std;

// this function counts the number of even numbers in both array
int getEvenNumberCount(int arr1[], int arr2[], int size1, int size2) {
    int evenNumberCount = 0;
  
    for (int i = 0; i < size1; i++) {
        if(arr1[i] % 2 == 0) {
            evenNumberCount++;
        }
    }
    for (int i = 0; i < size2; i++) {
        if(arr2[i] % 2 == 0) {
            evenNumberCount++;
        }
    }

    return evenNumberCount;
}


void choose_even_number (int arr1[], int arr2[], int size1, int size2) {
    // get count
    int evenNumberCount = getEvenNumberCount(arr1, arr2, size1, size2);
    // declare new array
    int totalEvenNumberArray[evenNumberCount];
    int totalArrayIndexCount = 0;
    for (int i = 0; i < size1; i++) {
        if(arr1[i] % 2 == 0) {
            totalEvenNumberArray[totalArrayIndexCount] = arr1[i];
            totalArrayIndexCount++;
        }
    }
    for (int i = 0; i < size2; i++) {
        if(arr2[i] % 2 == 0) {
            totalEvenNumberArray[totalArrayIndexCount] = arr2[i];
            totalArrayIndexCount++;
        }
    }
    for (int i = 0; i < totalArrayIndexCount; i++) {
        cout << totalEvenNumberArray[i] <<endl;
    }
}



int main(){
    int arr1[5] = {1,2,3,4,5}, arr2[5] = {6,7,8,9,10};

    choose_even_number(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0])); 

    return 0;
}