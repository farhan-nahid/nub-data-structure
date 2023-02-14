#include <iostream> 

using namespace std;

void delete_first_and_last_two (int arr[]) {
    int i = 0;
    while(arr[i]){
        i++;
    }
    
    if(i < 4) {
        cout << "Not Possible" << endl;
    } else if(i == 4){
        cout << "[]" << endl;
    } else{
        cout << "[ ";
        for(int j = 2; j<i-2; j++){
            cout << arr[j] << " ";
        }
        cout << "]" << endl;
    }
}

int main (){
    int arr1[9] = {1,2,3,4,5,6,7,8,99};
    delete_first_and_last_two(arr1);
    return 0;
}