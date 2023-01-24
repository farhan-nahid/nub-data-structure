# include <iostream>

using namespace std;

int main()
{
    int arr [10], sum = 0, avg = 0;

    for (int i = 0; i < 10; i++)
    {
      cin >>  arr[i];
      sum += arr[i];
    }
    
    avg = sum / 10;
    cout << "Avg Value is " << avg << endl;

    return 0;
}