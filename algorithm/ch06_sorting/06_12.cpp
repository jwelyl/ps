#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> A, B;

int main(void) {
    int x;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> x;
        A.push_back(x);
    }
    for(int i = 0; i < N; i++) {
        cin >> x;
        B.push_back(x);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for(int i = 0; i < K; i++) {
        if(A[i] >= B[i]) break;
        swap(A[i], B[i]);
    }

    x = 0;
    for(int i = 0; i < A.size(); i++)
        x += A[i];
    
    cout << x << '\n';
    return 0;
}