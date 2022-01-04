#include <iostream>
#include <vector>
using namespace std;

vector<int> food;
vector<int> dp;
int N;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    food.assign(N + 1, 0);
    dp.assign(N + 1, 0);

    for(int i = 1; i <= N; i++)
        cin >> food[i];

    dp[1] = food[1];
    dp[2] = food[2];
    dp[3] = food[1] + food[3];

    if(N > 3) {
        for(int i = 4; i <= N; i++) 
            dp[i] = max(dp[i - 2] + food[i], dp[i - 3] + food[i]);
    }

    // for(int i = 1; i <= N; i++)
    //     cout << dp[i] << ' ';
    cout << max(dp[N - 1], dp[N]) << '\n';
    
    return 0;
}