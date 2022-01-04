#include <iostream>
using namespace std;

int N, sol = 0;
int coins[4] = {500, 100, 50, 10};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    // sol += N / 500;
    // N = N % 500;
    // sol += N / 100;
    // N = N % 100;
    // sol += N / 50;
    // N = N % 50;
    // sol += N / 10;
    // N = N % 10;

    for(int i = 0; i < 4; i++) {
        sol += N / coins[i];
        N = N % coins[i];
    }

    cout << sol << '\n';

    return 0;    
}