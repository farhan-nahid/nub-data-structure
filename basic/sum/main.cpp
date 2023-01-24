# include <iostream>

using namespace std;

int main()
{
    int arr [10], sum = 0;

    for (int i = 0; i < 10; i++)
    {
      cin >>  arr[i];
      sum += arr[i];
    }

    cout << "Total Value is " << sum << endl;

    return 0;
}