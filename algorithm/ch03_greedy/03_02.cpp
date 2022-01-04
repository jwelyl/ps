#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int add = 0, sol = 0;
vector<int> arr;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    for(int i = 0; i < N; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    add = arr[0] * K + arr[1];  //  가장 큰 수 K번 더하고 그 다음으로 큰 수 한 번 더함
    sol = add * (M / (K + 1)) + arr[0] * (M % (K + 1));

    cout << sol << '\n';

    return 0;
}