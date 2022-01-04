#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M, C;
int cnt = 0, max_time = -INF;
vector<vector<pair<int, int> > > graph;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;

    dist[start] = 0;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()) {
        int now = pq.top().second;
        int now_d = -pq.top().first;
        pq.pop();

        if(dist[now] < now_d) continue;

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

    cin >> N >> M >> C;
    graph.assign(N + 1, vector<pair<int, int> >());
    dist.assign(N + 1, INF);

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    dijkstra(C);

    for(int i = 1; i <= N; i++) {
        if(i == C) continue;

        if(dist[i] != INF) {
            cnt++;
            max_time = max(max_time, dist[i]); 
        } 
    }

    cout << cnt << " " << max_time << '\n';

    return 0;
}