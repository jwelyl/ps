#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define INF 1e9
using namespace std;

int N, M, start;
vector<vector<pair<int, int> > > graph;
vector<int> dist;
vector<bool> visited;

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()) {
        int now_d = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < now_d)
            continue;

        for(int i = 0; i < graph[now].size(); i++) {
            int cost = now_d + graph[now][i].second;

            if(cost < dist[graph[now][i].first]) {
                dist[graph[now][i].first] = cost;
                pq.push(make_pair(-dist[graph[now][i].first], graph[now][i].first));
            }
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