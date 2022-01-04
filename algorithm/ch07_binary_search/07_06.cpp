#include <iostream>
#include <vector>
#define INF 999999999
using namespace std;

int N, M;
vector<int> arr, cnt;

int main(void) {
    int max_size = -INF, x;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> x;
        arr.push_back(x);

        if(x > max_size) max_size = x;
    }

    cnt.assign(max_size + 1, 0);
    for(int i = 0; i < arr.size(); i++)
        cnt[arr[i]] += 1;

    vector<int>().swap(arr);

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> x;
        arr.push_back(x);
    }

    for(int i = 0; i < arr.size(); i++) {
        if(cnt[arr[i]] != 0)
            cout << "yes ";
        else cout << "no ";
    }
    cout << '\n';

    return 0;
}