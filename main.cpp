#include <iostream>
#include <array>

using namespace std;

template<typename T, size_t H>
void shiftElement(int counter, array<T, H> &arr) {
    array<T, H> test;
    for (int i = 0; i < H; ++i) {
        test[(i + counter + H) % H] = arr[i];
    }
    arr = test;
};

int main() {
    array<int, 5> test = {1, 2, 3, 4, 5};
    shiftElement(4, test);
    for (const auto &element : test) {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}
