#include <iostream>
#include <vector>
using namespace std;

vector<int> A;
int N, B, C;
long long ans = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    cin >> B >> C;

    for(int i = 0; i < N; i++) {
        A[i] = (A[i] > B) ? (A[i] - B) : 0;
        ans += 1;

        if(A[i] % C != 0)
            ans += ((A[i] / C) + 1);
        else
            ans += A[i] / C;
    }

    cout << ans << "\n";

    return 0;
}