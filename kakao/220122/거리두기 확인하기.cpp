// https://programmers.co.kr/learn/courses/30/lessons/81302
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <iostream>
#define INF 987654321

using namespace std;
int n;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int m_dist(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

void reset(vector<vector<int> >& dist) {
    for(int i = 0; i < dist.size(); i++)
        for(int j = 0; j < dist[i].size(); j++)
            dist[i][j] = INF;
}

void bfs(int y, int x, vector<vector<char> > graph, vector<vector<int> >& dist) {
    queue<pair<int, pair<int, int> > > q;
    dist[y][x] = 0;
    q.push(make_pair(dist[y][x], make_pair(y, x)));

    while(!q.empty()) {
        int cur_d = q.front().first;
        int cur_y = q.front().second.first;
        int cur_x = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nd = cur_d + 1;
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= n || graph[ny][nx] == 'X' || dist[ny][nx] != INF)
                continue;

            dist[ny][nx] = nd;
            q.push(make_pair(nd, make_pair(ny, nx)));
        }
    }
}

vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;

    n = places.size();
    for(int tc = 0; tc < places.size(); tc++) {
        vector<vector<char> > graph;    //  그래프
        vector<pair<int, int> > pos;    //  각 응시자의 위치
        bool is_ok = true;              //  거리두기 지켜졌으면 true, 아니면 false;

        graph.assign(n, vector<char>());
        for(int i = 0; i < n; i++)
            graph[i].assign(n, ' ');

        for(int i = 0; i < places[tc].size(); i++) {
            string input = places[tc][i];
            vector<vector<int> > dist(n, vector<int>(n, INF));

            for(int j = 0; j < input.size(); j++) {
                graph[i][j] = input[j];
                if(graph[i][j] == 'P')
                    pos.push_back(make_pair(i, j));
            }

            for(int j = 0; j < pos.size(); j++) {
                int cur_y = pos[j].first;
                int cur_x = pos[j].second;

                reset(dist);
                bfs(cur_y, cur_x, graph, dist);

                for(int k = 0; k < pos.size(); k++) {
                    if(k == j) continue;

                    int ny = pos[k].first;
                    int nx = pos[k].second;

                    if(m_dist(cur_y, cur_x, ny, nx) > 2) continue;  //  manhattan dist가 2를 넘을 경우 ok
                    else {  //  manhattan dist가 2 이하일 경우
                        if(dist[ny][nx] <= 2) {  //  칸막이로 잘 막아지지도 않은 경우
                            is_ok = false;  //  현재 test case는 거리두기를 어김
                            break;
                        }
                    }
                }

                if(!is_ok) break;
            }

            if(!is_ok) break;
        }   //  for-i

        if(is_ok)
            answer.push_back(1);
        else
            answer.push_back(0);
    }   //  for-tc

    return answer;
}