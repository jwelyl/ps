// https://programmers.co.kr/learn/courses/30/lessons/81302#fn1
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>
#define INF     999999999

using namespace std;

vector<vector<char> > graph;
vector<vector<int> > dist;
vector<pair<int, int> > person;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool manhatton_dist(int y1, int x1, int y2, int x2) {
    return (abs(y2 - y1) + abs(x2 - x1) > 2);
}

void reset_dist() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
            dist[i][j] = INF;
    }
}

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    dist[y][x] = 0;
    q.push(make_pair(y, x));

    while(!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
                continue;

            else if(dist[ny][nx] == INF && graph[ny][nx] != 'X') {
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

vector<int> solution(vector<vector<string> > places) {
    vector<int> answer;

    for(int i = 0; i < 5; i++) {
        int ok = 1;
        vector<vector<char> >().swap(graph);
        vector<vector<int> >().swap(dist);
        vector<pair<int, int> >().swap(person);

        graph.assign(5, vector<char>());
        dist.assign(5, vector<int>());
        for(int j = 0; j < 5; j++) {
            graph[j].assign(5, 'X');
            dist[j].assign(5, INF);
        }

        for(int j = 0; j < 5; j++) {
            string str = places[i][j];

            for(int k = 0; k < 5; k++) {
                if(places[i][j][k] == 'O')
                    graph[j][k] = 'O';
                else if(places[i][j][k] == 'P') {
                    graph[j][k] = 'P';
                    person.push_back(make_pair(j, k));
                }
            }
        }

        for(int j = 0; j < person.size(); j++) {
            int y = person[j].first, x = person[j].second;
            reset_dist();

            bfs(y, x);

            for(int k = 0; k < person.size(); k++) {
                int ny = person[k].first, nx = person[k].second;

                if(ny != y || nx != x) {    //  ?????? ?????? ????????? ??????
                    if(dist[ny][nx] == INF) //  ???????????? ?????? ????????? ??? ?????? ?????? ????????? ??????
                        continue;
                
                    else {  //  ????????? ??? ?????? ??????
                        if(manhatton_dist(y, x, ny, nx))    //  ????????? ????????? 3 ????????? ??????
                            continue;
                        else {  //  ????????? ????????? 2 ????????? ??????
                            if(dist[ny][nx] >= 3)  //  ????????? ????????? ???????????? ???????????? ?????? ?????? ??????
                                continue;
                            else {  //  ???????????? ??????
                                ok = 0;
                                break;
                            }
                        }
                    }
                }
            }

            if(ok == 0) break;  //  ???????????? ?????? ????????????????????? ????????? ?????? ?????? ??????
        }

        answer.push_back(ok);

    }

    return answer;
}