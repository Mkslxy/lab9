#include <iostream>
#include <array>
#include <vector>
#include <deque>

using namespace std;

template<typename T, size_t H>
void shiftElement(int counter, array<T, H> &arr) {
    array<T, H> test;
    for (int i = 0; i < H; ++i) {
        test[(i + counter + H) % H] = arr[i];
    }
    arr = test;
};

template<typename T>
void insertIntoVector(vector<T> &vec, size_t pos, const vector<T> &range) {
    vec.resize(vec.size() + range.size());
    for (size_t i = vec.size() - 1; i >= pos + range.size(); --i) {
        vec[i] = vec[i - range.size()];
    }
    for (size_t i = 0; i < range.size(); ++i) {
        vec[pos + i] = range[i];
    }
}

template<typename T>
void removeElement(deque<T> &deq) {
    size_t middleIndex = deq.size() / 2;
    if (deq.size() % 2 == 0) {
        deq.erase(deq.begin() + middleIndex - 1, deq.begin() + middleIndex + 1);
    } else {
        deq.erase(deq.begin() + middleIndex);
    }
}

int main() {

    array<int, 5> test = {1, 2, 3, 4, 5};
    shiftElement(3, test);
    for (const auto &element: test) {
        cout << element << " ";
    }

    cout << endl;

    vector<int> vec = {1, 2, 6, 7};
    vector<int> range = {3, 4, 5};
    insertIntoVector(vec, 1, range);

    for (int i = 0; i < vec.size(); ++i) {
        printf("%d ", vec[i]);
    }

    cout << endl;

    deque<int> deq = {1, 2, 3, 4, 5};
    removeElement(deq);
    for (const auto &element: deq) {
        cout << element << " ";
    }
    cout << endl;

    cout << endl;
    return 0;
}
