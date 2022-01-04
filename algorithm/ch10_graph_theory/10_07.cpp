#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> parents;

int find_parent(vector<int>& parents, int x) {
    if(parents[x] != x)
        parents[x] = find_parent(parents, parents[x]);

    return parents[x];
} 

void union_parent(vector<int>& parents, int a, int b) {
    a = find_parent(parents, a);
    b = find_parent(parents, b);

    if(a == b) return;

    if(a < b)
        parents[b] = a;
    else
        parents[a] = b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i <= N; i++)
        parents.push_back(i);

    for(int i = 0; i < M; i++) {
        int op, a, b;
        cin >> op >> a >> b;

        if(op == 0) 
            union_parent(parents, a, b);
        else if(op == 1) {
            a = find_parent(parents, a);
            b = find_parent(parents, b);

            if(a == b) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}