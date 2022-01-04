#include <iostream>
#include <vector>
#define INF 999999999
using namespace std;

int N, M;
vector<int> coins;
vector<int> dp;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        coins.push_back(x);
    }

    dp.assign(M + 1, INF);
    dp[0] = 0;

    for(int i = 0; i < N; i++) {
        for(int j = coins[0]; j <= M; j++) {
            if(dp[j - coins[i]] != INF)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    if(dp[M] == INF)
        cout << -1 << '\n';
    else
        cout << dp[M] << '\n';
    
    return 0;
}