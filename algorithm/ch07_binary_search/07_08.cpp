#include <iostream>
#include <vector>
#define INF 999999999
using namespace std;

int N, target;
vector<int> arr;

int binary_search(vector<int> arr, int target, int start, int end) {
    int mid, cut;

    while(start <= end) {
        mid = (start + end) / 2;
        cut = 0;

        for(int i = 0; i < N; i++) 
            cut += ((arr[i] - mid) > 0 ? arr[i] - mid : 0);

        if(cut == target) return mid;
        else if(cut > target) start = mid + 1;
        else end = mid - 1;
    }

    return mid;
}

int main(void) {
    int max_h = -INF;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> target;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if(max_h < x) max_h = x;
        arr.push_back(x);
    }

    cout << binary_search(arr, target, 0, max_h) << '\n';
    return 0;
}