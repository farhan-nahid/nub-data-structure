#include <iostream>

using namespace std;

int main() {
    const int ARRAY_ONE_SIZE = 5;
    const int ARRAY_TWO_SIZE = 4;
    int array_one[ARRAY_ONE_SIZE] = {1, 2, 3, 4, 6};
    int array_two[ARRAY_TWO_SIZE] = {6, 7, 8, 9};

    // Check if the two arrays have at least one common member
    bool hasCommonMember = false;
    for (int i = 0; i < ARRAY_ONE_SIZE; i++) {
        for (int j = 0; j < ARRAY_TWO_SIZE; j++) {
            if (array_one[i] == array_two[j]) {
                hasCommonMember = true;
                break;
            }
        }
        if (hasCommonMember) {
            break;
        }
    }

    // Print the result
    if (hasCommonMember) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
