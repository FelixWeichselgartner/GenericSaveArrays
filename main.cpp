#include <iostream>
using namespace std;
#include "Array.hpp"

cArray(int)

int main() {
    Array_Type(int) arr1 = Array(int, 16);

    for (int i = 0; i < 16; i++) {
        arr1.set(i, i);
    }

    for (int i = 0; i < 16; i++) {
        int v = arr1.get(i);
        cout << v << " ";
    }
    cout << endl;

    int err = arr1.get(-1);

    return 0;
}