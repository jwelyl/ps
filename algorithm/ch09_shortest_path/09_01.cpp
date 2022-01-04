#include <iostream>
#include <vector>
#include <utility>
#define INF 1e9
using namespace std;

int N, M, start;
vector<vector<pair<int, int> > > graph;
vector<int> dist;
vector<bool> visited;

int get_smallest_node() {
    int min_value = INF;
    int idx = 0;

    for(int i = 1; i <= N; i++) {
        if(dist[i] < min_value && !visited[i]) {
            min_value = dist[i];
            idx = i;
        }
    }

    return idx;
}

void dijkstra(int start) {
    dist[start] = 0;
    visited[start] = true;

    for(int i = 0; i < graph[start].size(); i++)
        dist[graph[start][i].first] = graph[start][i].second;

    for(int i = 0; i < N - 1; i++) {
        int now = get_smallest_node();
        visited[now] = true;

        for(int j = 0; j < graph[now].size(); j++) {
            int cost = dist[now] + graph[now][j].second;

            if(cost < dist[graph[now][j].first])
                dist[graph[now][j].first] = cost;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    cin >> start;

    graph.assign(N + 1, vector<pair<int, int> >());
    dist.assign(N + 1, INF);
    visited.assign(N + 1, false);
    
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    dijkstra(start);

    for(int i = 1; i <= N; i++) {
        if(dist[i] == INF)
            cout << "INF\n";
        else 
            cout << dist[i] << '\n';
    }

    return 0;
}