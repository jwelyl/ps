// https://programmers.co.kr/learn/courses/30/lessons/67259
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <iostream>
#define NONE    -1
#define R       0
#define D       1
#define L       2
#define U       3
#define INF 987654321

using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int N;
vector<vector<int> > cost[4];

void bfs(vector<vector<int> > board) {
    queue<pair<pair<int, int>, pair<int, int> > > q;
    // q.push
    q.push(make_pair(make_pair(0, 0), make_pair(NONE, cost[0][0][0])));

    while(!q.empty()) {
        int cur_y = q.front().first.first;
        int cur_x = q.front().first.second;
        int cur_d = q.front().second.first;
        int cur_c = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            int nd = i;
            int nc = cur_c;

            if(ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == 1)
                continue;

            if(cur_d == NONE)
                nc += 100;
            else if(cur_d % 2 != nd % 2)
                nc += 600;
            else
                nc += 100;
            
            if(cost[nd][ny][nx] >= nc) {
                cost[nd][ny][nx] = nc;
                q.push(make_pair(make_pair(ny, nx), make_pair(nd, cost[i][ny][nx])));
            }
        }
    }
}

int solution(vector<vector<int> > board) {
    N = board.size();
    for(int i = 0; i < 4; i++) {
        cost[i].assign(N, vector<int>());
        for(int j = 0; j < N; j++)
            cost[i][j].assign(N, INF);
        cost[i][0][0] = 0;
    }
    
    // for(int i = 0; i < 4; i++) {
    //     for(int j = 0; j < N; j++) {
    //         for(int k = 0; k < N; k++)
    //             cout << cost[i][j][k] << ' ';
    //         cout << '\n';
    //     }
    //     cout << "--------------------------------------\n";
    // }
    bfs(board);

    return min(min(cost[0][N - 1][N - 1], cost[1][N - 1][N - 1]), min(cost[2][N - 1][N - 1], cost[3][N - 1][N - 1]));
}