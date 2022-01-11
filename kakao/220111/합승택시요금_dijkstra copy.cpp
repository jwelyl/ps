// https://programmers.co.kr/learn/courses/30/lessons/72413
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define INF 987654321

using namespace std;

vector<vector<pair<int, int> > > graph;
vector<int> dist_s; //  s에서부터 최단거리
vector<int> dist_i; //  중간 지점 i부터 최단거리

void dijkstra(int start, vector<int>& dist) {
    priority_queue<pair<int, int> > pq;

    //  dist 초기화
    for(int i = 0; i < dist.size(); i++)
        dist[i] = INF;
    dist[start] = 0;

    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()) {
        int now_dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] < now_dist)
            continue;

        for(int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].first;
            int new_dist = now_dist + graph[now][i].second;

            if(new_dist < dist[next]) {
                dist[next] = new_dist;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int> > fares) {
    int answer = 0;
    int dist_a, dist_b; //  각각 s에서 a, b로 최단거리로 가는 비용

    graph.assign(n + 1, vector<pair<int, int> >());
    dist_s.assign(n + 1, INF);
    dist_i.assign(n + 1, INF);

    for(int i = 0; i < fares.size(); i++) {
        int a, b, cost;
        a = fares[i][0];
        b = fares[i][1];
        cost = fares[i][2];

        graph[a].push_back(make_pair(b, cost));
        graph[b].push_back(make_pair(a, cost));
    }

    dijkstra(s, dist_s);    //  시작 지점 s로부터의 최단거리

    answer = (dist_s[a] != INF && dist_s[b] != INF) ? (dist_s[a] + dist_s[b]) : INF;    //  따로 가는 경우의 거리 계산

    for(int i = 1; i <= n; i++) {
        //  a->i 가는 비용 = i->a 가는 비용(양방향 그래프)
        int tmp = dist_s[i];    //  시작 지점 s로부터 i까지의 최단거리
        dijkstra(i, dist_i);    //  중간 지점 i로부터의 최단거리

        tmp = (tmp != INF && dist_i[a] != INF && dist_i[b] != INF) ? tmp + dist_i[a] + dist_i[b] : INF; //  (s->i 거리) + (i->a 거리) + (i->b 거리)   
        answer = min(answer, tmp);
    }

    return answer;
}