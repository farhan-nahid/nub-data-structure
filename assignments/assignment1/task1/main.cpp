#include <iostream>

using namespace std;

class Output{
    public:
        int min;
        int max;
};

Output min_and_max(int arr[], int size){
    Output outputObj;
    outputObj.min = arr[0];
    outputObj.max = arr[0];

    for(int i = 0; i < size; i++){
        if(arr[i] < outputObj.min){
            outputObj.min = arr[i];
        }
        if(arr[i] > outputObj.max){
            outputObj.max = arr[i];
        }
    }

    return outputObj;
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10}, size = 10;

    Output result =  min_and_max(arr, size);

    cout << "Min value is\t" << result.min << endl;
    cout << "Max value is\t" << result.max << endl;

    return 0;
}