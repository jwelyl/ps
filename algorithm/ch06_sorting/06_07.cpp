#include <iostream>
#include <algorithm>
using namespace std;

int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

void print_sorted_arr(int* arr, int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

int main(void) {
    sort(arr, arr + sizeof(arr) / sizeof(int));
    print_sorted_arr(arr, sizeof(arr) / sizeof(int));
    return 0;
}