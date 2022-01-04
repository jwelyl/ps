#include <iostream>
#include <vector>
using namespace std;

int V, E;
bool cycle = false;
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

        if(find_parent(parent, a) == find_parent(parent, b)) {
            cycle = true;
            break;
        }
        union_parent(parent, a, b);
    }

    if(cycle)
        cout << "사이클이 발생했습니다.\n";
    else 
        cout << "사이클이 발생하지 않았습니다.\n";
        
    return 0;
}

