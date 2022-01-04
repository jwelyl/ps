#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int V, E, min_cost = 0;
vector<int> parent;
vector<pair<int, pair<int, int> > > edges;

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

void kruskal(vector<pair<int, pair<int, int> > > edges) {
    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++) {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int cost = edges[i].first;

        if(find_parent(parent, a) != find_parent(parent, b)) {
            union_parent(parent, a, b);
            min_cost += cost;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;

    for(int i = 0; i <= V; i++)
        parent.push_back(i);
    
    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back(make_pair(c, make_pair(a, b)));
    }

    // for(int i = 0; i < edges.size(); i++)
    //     cout << "(" << edges[i].second.first << ", " << edges[i].second.second <<") : " << edges[i].first << "\n";
    // cout << '\n';

    kruskal(edges);

    // for(int i = 0; i < edges.size(); i++)
    //     cout << "(" << edges[i].second.first << ", " << edges[i].second.second <<") : " << edges[i].first << "\n";
    // cout << '\n';

    cout << min_cost << '\n';
   
    return 0;
}

