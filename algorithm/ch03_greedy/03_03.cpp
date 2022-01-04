#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, sol = 0;
vector<vector<int> > arr;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    arr.assign(N, vector<int>());
    
    for(int i = 0; i < N; i++) {
        int min;
        for(int j = 0; j < M; j++) {
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
        // sort(arr[i].begin(), arr[i].end());
        min = *min_element(arr[i].begin(), arr[i].end());
        sol = max(sol, min);
    }

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < M; j++) 
    //         cout << arr[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << sol << '\n';
    return 0;
}