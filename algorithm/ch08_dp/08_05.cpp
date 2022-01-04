#include <iostream>
#include <algorithm>
#include <vector>
#define INF 999999999
using namespace std;

int X;
vector<int> dp;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> X;
    dp.assign(X + 1, INF);

    dp[1] = 0;

    for(int i = 2; i <= X; i++) {
        if(i % 5 == 0) dp[i] = min(dp[i], dp[i / 5] + 1);
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    cout << dp[X] << '\n';

    return 0;
}