#include <iostream>
#include <vector>
using namespace std;

int V, E;
vector<int> parent;

int find_parent(vector<int>& parent, int x) {
    if(parent[x] != x)
        parent[x] = find_parent(parent, parent[x]);
    return parent[x];
}

void union_parent(vector<int>& parent, int a, int b) {
    a = find_parent(parent, a);
    b = find_parent(parent, b);

    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;

    for(int i = 0; i <= V; i++)
        parent.push_back(i);
    
    for(int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        union_parent(parent, a, b);
    }

    cout << "각 원소가 속한 집합 : ";
    for(int i = 1; i <= V; i++)
        cout << find_parent(parent, i) << " ";
    cout << "\n";

    cout << "부모 테이블 : ";
    for(int i = 1; i <= V; i++)
        cout << parent[i] << " ";
    cout << '\n';

    return 0;
}

