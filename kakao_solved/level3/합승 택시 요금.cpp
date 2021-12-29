// https://programmers.co.kr/learn/courses/30/lessons/72413
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
#define INF      1e9

using namespace std;

vector<vector<pair<int, int> > > graph;
vector<int> dist_s, dist_a, dist_b;

void reset_dist(vector<int>& dist) {
    for(int i = 0; i < dist.size(); i++)
        dist[i] = INF;
}

void dijkstra(vector<int>& dist, int start) {
    priority_queue<pair<int, int> > pq;

    reset_dist(dist);
    dist[start] = 0;
    pq.push(make_pair(-dist[start], start));

    while(!pq.empty()) {
        int now_cost = -pq.top().first;
        int now_pos = pq.top().second;
        pq.pop();

        if(dist[now_pos] < now_cost)
            continue;

        for(int i = 0; i < graph[now_pos].size(); i++) {
            if(now_cost + graph[now_pos][i].second < dist[graph[now_pos][i].first]) {
                dist[graph[now_pos][i].first] = now_cost + graph[now_pos][i].second;
                pq.push(make_pair(-dist[graph[now_pos][i].first], graph[now_pos][i].first));
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int individual = 0;       //  시작점에서 각각의 목적지까지 따로 갈 경우의 비용 합
    int together = INF;       //  시작점에서 합승 후 찢어질 경우 비용 합
    int tmp = INF;

    graph.assign(n + 1, vector<pair<int, int> >());
    dist_s.assign(n + 1, INF);
    dist_a.assign(n + 1, INF);
    dist_b.assign(n + 1, INF);

    for(int i = 0; i < fares.size(); i++) {
        int from, to, cost;

        from = fares[i][0];
        to = fares[i][1];
        cost = fares[i][2];

        graph[from].push_back(make_pair(to, cost));
        graph[to].push_back(make_pair(from, cost));
    }

    dijkstra(dist_s, s);    //  시작점에서 모든 점까지의 거리
    for(int i = 1; i <= n; i++)
        cout << dist_s[i] << ' ';
    cout << '\n';


    individual = dist_s[a] + dist_s[b]; //  따로 갈 경우의 비용 합

    dijkstra(dist_a, a);    //  도착점 a에서 모든 점까지의 거리(양방향)
    dijkstra(dist_b, b);    //  도착점 b에서 모든 점까지의 거리(양방향)

    for(int i = 1; i <= n; i++) {
        if(dist_s[i] == INF || dist_a[i] == INF || dist_b[i] == INF)  //  i 지점에서 따로 갈 경우 적어도 둘 중 한명은 도착 불가
            continue;
        
        //  s에서 i까지 비용 + a에서 i까지 비용(i에서 a까지의 비용) + b에서 i까지 비용(i에서 b까지의 비용)
        together = min(together, dist_s[i] +dist_a[i] + dist_b[i]);
    }
    
    answer = min(individual, together);

    return answer;
}