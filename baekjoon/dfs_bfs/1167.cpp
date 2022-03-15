#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int V, root, ans = 0;
vector<vector<pair<int, int> > > tree;
vector<bool> visited;
vector<int> dist;

void reset() {
    for(int i = 0; i <= V; i++) {
        visited[i] = false;
        dist[i] = 0;
    }
}

void dfs(int v) {
    visited[v] = true;

    for(int i = 0; i < tree[v].size(); i++) {
        int n = tree[v][i].first;
        int d = tree[v][i].second;

        if(!visited[n]) {
            dist[n] = dist[v] + d;
            dfs(n);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V;

    tree.assign(V + 1, vector<pair<int, int> >());
    visited.assign(V + 1, false);
    dist.assign(V + 1, 0);

    for(int i = 0; i < V; i++) {
        int u, v, d;
        cin >> u;

        while(true) {
            cin >> v;

            if(v == -1)
                break;
            cin >> d;

            tree[u].push_back(make_pair(v, d));
        }
    }

    dfs(1);
    root = max_element(dist.begin() + 1, dist.end()) - dist.begin();

    reset();

    dfs(root);
    ans = *max_element(dist.begin() + 1, dist.end());
    cout << ans << '\n';

    return 0;
}