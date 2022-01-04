#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr1, arr2;

int binary_search(vector<int> arr, int target, int start, int end) {
    while(start <= end) {
        int mid = (start + end) / 2;
        
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) end = mid - 1;
        else start = mid + 1;
    }

    return -1;
}

int main(void) {
    int x;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x;
        arr1.push_back(x);
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> x;
        arr2.push_back(x);
    }

    sort(arr1.begin(), arr1.end());

    for(int i = 0; i < M; i++) {
        int res = binary_search(arr1, arr2[i], 0, N - 1);
        if(res == -1) cout << "no ";
        else cout << "yes ";
    }
    cout << '\n';

    return 0;
}