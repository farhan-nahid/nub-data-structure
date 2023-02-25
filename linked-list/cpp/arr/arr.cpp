#include <iostream>

using namespace std;

// min & max from arr

void Min( int box[] , int size){
    int min = box[0], max = box[0];

    for(int i = 0 ; i < size; i++){
        if(box[i] > max){
            max = box[i];
        }
        if(box[i] < min){
            min = box[i];
        }
    }

    cout << " Min " << min <<  " Max " << max << endl; 
}

// arr insert

void insert_value( int box[], int size, int index, int value ){
    for(int i = size; i>=index; i--){
        box[i+1] = box[i];
    }

    box[index] = value;

    for(int i =0; i<size; i++){
        cout << box[i] << ' ';
    }

    cout << endl;

}

// arr delete

void delete_value(int box[], int size, int index){
    for(int i = index; i<size; i++){

        box[i] = box[i+1];
    }

      for(int i =0; i<size; i++){
        cout << box[i] << ' ';
    }

    cout << endl;
}

// delete by value (2 & 5) ------ arr[5] = {-11,2,34,5,6}

void delete_by_value(int box[], int size){
    int new_arr[size];
    int  j= 0, deleted_count=0;

    for(int i = 0; i < size; i++) {
        new_arr[i] = 0;
    }

    for(int i =0; i < size; i++){
        if( box[i] == 2 || box[i] == 5 ){
          deleted_count +=1;
        }else{
            new_arr[j] = box[i];
            j +=1;
        }
    }

 

    for(int i =deleted_count ; i>=0; i--){
        int temp = size - deleted_count;
        new_arr[temp + deleted_count - 1] = 0;
         deleted_count --; 
    }
   

    for(int i =0 ; i< size; i++){
        cout << new_arr[i] << ' ';
    }

    cout << endl;

}


int main(){
    int arr[5] = {-11,2,34,5,6};

    Min(arr, 5);
    insert_value(arr, 6, 3, 8);
    // delete_value(arr, 5, 3);
    delete_by_value(arr, 5);

    return 0;
}