#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> map;

int N, M;

int main(void) {
    int x;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x;
        map[x] = 1;
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> x;
        if(map[x] != 1)
            cout << "no ";
        else cout << "yes ";
    }
    cout << '\n';
    return 0;
}