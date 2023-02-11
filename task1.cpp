#include <iostream>

using namespace std;

int main (){

int arr  [5];

for(int i =0; i<5; i++){
    cin >> arr[i];
  for (int j= 0; j<=i; j++){
    cout << arr[j] << " ";
  }
}

return 0;
}
