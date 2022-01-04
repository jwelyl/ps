#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;
int n_edges = 0,min_cost = 0;
vector<int> parents;
vector<pair<int, pair<int, int> > > edges;

int find_parent(vector<int>& parents, int x) {
    if(parents[x] != x)
        parents[x] = find_parent(parents, parents[x]);

    return parents[x];
}

void union_parents(vector<int>& parents, int a, int b) {
    a = find_parent(parents, a);
    b = find_parent(parents, b);

    if(a == b) return;

    if(a < b) 
        parents[b] = a;
    else
        parents[a] = b;
}

void kruskal(vector<pair<int, pair<int, int> > >& edges, vector<int> parents) {
    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if(find_parent(parents, a) != find_parent(parents, b)) {
            union_parents(parents, a, b);
            n_edges += 1;
            min_cost += cost;
        }

        if(n_edges == N - 2) break;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N + 1; i++)
        parents.push_back(i);

    for(int i = 0; i < M; i++) {
        int a, b, cost;

        cin >> a >> b >> cost;
        edges.push_back(make_pair(cost, make_pair(a, b)));
    }

    kruskal(edges, parents);
    cout << min_cost << '\n';
    return 0;
}