#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> dp;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    dp.assign(N + 1, 0);
    dp[1] = 1;
    
    if(N >= 2)
        dp[2] = 3;
    if(N >= 3) {
        for(int i = 3; i <= N; i++)
            dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 796796;
    }
    cout << dp[N] << '\n';
    return 0;
}