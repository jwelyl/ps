#include <iostream>
#include <vector>
using namespace std;

int N, target, result;
vector<int> arr;

int binary_search(vector<int> arr, int target, int start, int end) {
    if(start > end) return -1;

    int mid = (start + end) / 2;

    if(arr[mid] == target) return mid;

    else if(arr[mid] < target) return binary_search(arr, target, mid + 1, end);
    else return binary_search(arr, target, start, mid - 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> target;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    result = binary_search(arr, target, 0, N - 1);

    if(result == -1)
        cout << "원소가 존재하지 않습니다.\n";
    else
        cout << result + 1 << '\n';
    
    return 0;
}