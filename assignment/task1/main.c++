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
        if(outputObj.min < arr[i]){
            outputObj.min = arr[i];
        }
        if(outputObj.max > arr[i]){
            outputObj.max = arr[i];
        }
    }

    return outputObj;
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10}, size = 10;

    Output output =  min_and_max(arr, size);

    cout << "Min value is\t" << output.min << endl;
    cout << "Max value is\t" << output.max << endl;

    return 0;
}