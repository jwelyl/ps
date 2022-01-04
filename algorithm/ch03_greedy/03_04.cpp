#include <iostream>
using namespace std;

int N, K, sol = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    // while(N > 1) {
    //     if(N % K == 0) {
    //         N /= K;
    //     }
    //     else N -= 1;

    //     sol++;
    // }

    while(N > 1) {
        if(N % K != 0) {
            sol += (N % K);
            N -= (N % K);
        }
        else {
            sol += 1;
            N /= K;
        }
    }

    if(N == 0) sol -= 1;

    cout << sol << '\n';

    return 0;
}