// https://programmers.co.kr/learn/courses/30/lessons/67259
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#define START   0   //  시작점에서 이동방향
#define HORIZ   1   //  수평 이동
#define VERT   -1   //  수직 이동
#define INF     987654321

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int n, sy = 0, sx = 0, endy, endx;
vector<vector<int> > cost;
// vector<vector<int> > direction;

void bfs(vector<vector<int> > board) {
    queue<pair<pair<int, int>, pair<int, int> > > q;
    cost[sy][sx] = 0;
    // direction[sy][sx] = START;
    q.push(make_pair(make_pair(sy, sx), make_pair(START, cost[sy][sx])));

    while(!q.empty()) {
        int cur_y = q.front().first.first;
        int cur_x = q.front().first.second;
        int cur_dir = q.front().second.first;
        int cur_cost = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            int next_dir;
            int next_cost = cur_cost;

            if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= n || board[next_y][next_x] == 1)
                continue;

            if(cur_dir == START) {
                if(next_x != cur_x) 
                    next_dir = HORIZ;
                else if(next_y != cur_y)
                    next_dir = VERT;
                next_cost += 100;
            }
            else if(cur_dir == HORIZ) {
                if(next_y != cur_y) {
                    next_dir = VERT;
                    next_cost += 600;
                }
                else {
                    next_dir = cur_dir;
                    next_cost += 100;
                }
            }
            else if(cur_dir == VERT) {
                if(next_x != cur_x) {
                    next_dir = HORIZ;
                    next_cost += 600;
                }
                else {
                    next_dir = cur_dir;
                    next_cost += 100;
                }
            }

            if(cost[next_y][next_x] >= next_cost) {
                cost[next_y][next_x] = next_cost;
                // direction[next_y][next_x] = next_dir;
                q.push(make_pair(make_pair(next_y, next_x), make_pair(next_dir, next_cost)));
            }
            // else if(next_dir != direction[next_y][next_x]) {
            //     // cout << "방향이 바뀔 경우\n";
            //     direction[next_y][next_x] = next_dir;
            //     q.push(make_pair(make_pair(next_y, next_x), make_pair(next_dir, next_cost)));
            // }
        }
    }
}

int solution(vector<vector<int> > board) {
    int answer = 0;

    n = board.size();
    endy = n - 1;
    endx = n - 1;

    cost.assign(n, vector<int>());
    // direction.assign(n, vector<int>());
    for(int i = 0; i < n; i++) {
        cost[i].assign(n, INF);
        // direction[i].assign(n, START);
    }

    bfs(board);
    answer = cost[endy][endx];
    return answer;
}