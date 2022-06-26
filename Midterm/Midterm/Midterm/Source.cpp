#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "IntStack.h"

using namespace std;
void increase(int* a, int size, int& value) {
    for (int i = 0; i < size; i++) {
        a[i] += value;
    }

}

int main() {
    int a[3] = {10,20,30};
    int v = 100;
    for (int s : a) {
        cout << s << endl;
    }
    increase(a, 3, v);

    for (int s : a) {
        cout << s << endl;
    }
    return 0;
}