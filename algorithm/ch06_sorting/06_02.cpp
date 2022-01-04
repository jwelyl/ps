#include <iostream>
#include <algorithm>
using namespace std;

int arr[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

void insertion_sort(int* arr, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0; j--) {
            if(arr[j] < arr[j - 1]) 
                swap(arr[j], arr[j - 1]);
            else 
            break;
        }
    }
}

void print_sorted_arr(int* arr, int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

int main(void) {
    insertion_sort(arr, sizeof(arr) / sizeof(int));
    print_sorted_arr(arr, sizeof(arr) / sizeof(int));
    return 0;
}