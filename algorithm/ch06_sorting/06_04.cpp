#include <iostream>
#include <algorithm>
using namespace std;

int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

void quick_sort(int* arr, int start, int end) {
    if(start >= end) return;

    int pivot = start;
    int left = start + 1;
    int right = end;

    while(left <= right) {
        while(left <= end && arr[left] <= arr[pivot])
            left++;
        while(right > start && arr[right] >= arr[pivot])
            right--;

        if(left > right)
            swap(arr[right], arr[pivot]);
        else
            swap(arr[left], arr[right]);
    }

    quick_sort(arr, start, right - 1);
    quick_sort(arr, right + 1, end);
}

void print_sorted_arr(int* arr, int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

int main(void) {
    quick_sort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    print_sorted_arr(arr, sizeof(arr) / sizeof(int));
    return 0;
}