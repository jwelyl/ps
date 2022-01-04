#include <iostream>
#include <algorithm>
using namespace std;

int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

void selection_sort(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        int min_idx = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[min_idx] > arr[j])
                min_idx = j;
        }

        swap(arr[min_idx], arr[i]);
    }
}

void print_sorted_arr(int* arr, int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

int main(void) {
    selection_sort(arr, sizeof(arr) / sizeof(int));
    print_sorted_arr(arr, sizeof(arr) / sizeof(int));
    return 0;
}