// https://programmers.co.kr/learn/courses/30/lessons/72415
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iostream>
#define INF 987654321
using namespace std;

int n;
int cur_y;
int cur_x;
vector<vector<pair<int, int> > > pos;
unordered_map<int, int> card_map;
vector<int> cards;

int m_dist(int x1, int x2) {
    return abs(x2 - x1);
}

int m_dist(int y1, int x1, int y2, int x2) {
    return abs(y2 - y1) + abs(x2 - x1);
}

int move_yx(int from_y, int from_x, int to_y, int to_x, vector<vector<int> > board) {  //  현재 카드에서 목적 카드까지 y축-x축 순서로 이동했을 때 최소 거리
    int diff = m_dist(from_y, from_x, to_y, to_x);
    int dy = INF, dx = INF;
    int y_dist = m_dist(from_y, to_y), x_dist = m_dist(from_x, to_x);
    int y_mid1, y_mid2, x_mid1, x_mid2;
    
    if(0 <= y_dist || y_dist <= 1) dy = y_dist;
    else if(y_dist == 2) {
        y_mid1 = (from_y + to_y) / 2;
        if(board[y_mid1][from_x] != 0)
            dy = 2;
        else
            dy = 1;
    }
    else {
        if(from_y < to_y) {
            y_mid1 = from_y + 1;
            y_mid2 = from_y + 2;
        }
        else {
            y_mid1 = from_y - 1;
            y_mid2 = from_y - 2;
        }

        if(board[y_mid1][from_x] != 0 && board[y_mid2][from_x] != 0)
            dy = 3;
        else if(board[y_mid1][from_x] == 0 && board[y_mid2][from_x] == 0)
            dy = 1;
        else
            dy = 2;
    }

    if(0 <= x_dist || x_dist <= 1) dx = x_dist;
    else if(x_dist == 2) {
        x_mid1 = (from_x + to_x) / 2;
        if(board[to_y][x_mid1] != 0)
            dx = 2;
        else
            dx = 1;
    }
    else {
        if(from_x < to_x) {
            x_mid1 = from_x + 1;
            x_mid2 = from_x + 2;
        }
        else {
            x_mid1 = from_x - 1;
            x_mid2 = from_x - 2;
        }

        if(board[to_y][x_mid1] != 0 && board[to_y][x_mid2] != 0)
            dx = 3;
        else if(board[to_y][x_mid1] == 0 && board[to_y][x_mid2] == 0)
            dx = 1;
        else
            dx = 2;
    }

    diff = min(diff, dy + dx);
    return diff;
} 

int move_xy(int from_y, int from_x, int to_y, int to_x, vector<vector<int> > board) {  //  현재 카드에서 목적 카드까지 x축-y축 순서로 이동했을 때 최소 거리
    int diff = m_dist(from_y, from_x, to_y, to_x);
    int dy = INF, dx = INF;
    int y_dist = m_dist(from_y, to_y), x_dist = m_dist(from_x, to_x);
    int y_mid1, y_mid2, x_mid1, x_mid2;
    
    if(0 <= x_dist || x_dist <= 1) dx = x_dist;
    else if(x_dist == 2) {
        x_mid1 = (from_x + to_x) / 2;
        if(board[from_y][x_mid1] != 0)
            dx = 2;
        else
            dx = 1;
    }
    else {
        if(from_x < to_x) {
            x_mid1 = from_x + 1;
            x_mid2 = from_x + 2;
        }
        else {
            x_mid1 = from_x - 1;
            x_mid2 = from_x - 2;
        }

        if(board[from_y][x_mid1] != 0 && board[from_y][x_mid2] != 0)
            dx = 3;
        else if(board[from_y][x_mid1] == 0 && board[from_y][x_mid2] == 0)
            dx = 1;
        else
            dx = 2;
    }

    if(0 <= y_dist || y_dist <= 1) dy = y_dist;
    else if(y_dist == 2) {
        y_mid1 = (from_y + to_y) / 2;
        if(board[y_mid1][to_x] != 0)
            dy = 2;
        else
            dy = 1;
    }
    else {
        if(from_y < to_y) {
            y_mid1 = from_y + 1;
            y_mid2 = from_y + 2;
        }
        else {
            y_mid1 = from_y - 1;
            y_mid2 = from_y - 2;
        }

        if(board[y_mid1][to_x] != 0 && board[y_mid2][to_x] != 0)
            dy = 3;
        else if(board[y_mid1][to_x] == 0 && board[y_mid2][to_x] == 0)
            dy = 1;
        else
            dy = 2;
    }

    diff = min(diff, dy + dx);
    return diff;
} 

void reset_board(vector<vector<int> > origin, vector<vector<int> >& cpy) {
    for(int i = 0; i < origin.size(); i++) {
        for(int j = 0; j < origin[i].size(); j++)
            cpy[i][j] = origin[i][j];
    }
}


int solution(vector<vector<int> > board, int r, int c) {
    int answer = INF;
    vector<vector<int> > board_cpy;

    n = board.size();
    cur_y = r;
    cur_x = c;
    pos.assign(7, vector<pair<int, int> >());
    board_cpy.assign(n, vector<int>(n, 0));
    reset_board(board, board_cpy);

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[i].size(); j++) {
            if(1 <= board[i][j] && board[i][j] <= 6) {
                if(card_map[board[i][j]] == 0) {
                    card_map[board[i][j]] = 1;
                    cards.push_back(board[i][j]);
                }
                pos[board[i][j]].push_back(make_pair(i, j));
            }
        }
    }
    sort(cards.begin(), cards.end());

    do {    //  카드 찾아서 뒤집는 순서
        int result = INF;
        int tmp1 = 0, result1 = INF;
        for(int i = 0; i < cards.size(); i++)
            cout << cards[i] << ' ';
        cout << '\n';

        reset_board(board, board_cpy);
        for(int i = 0; i < cards.size(); i++) {
            int c = cards[i];
            int tmp2, result2 = INF;
            int tcy = cur_y, tcx = cur_x;

            for(int j = 0; j < 2; j++) {
                int y1, x1, y2, x2;

                if(j == 0) {
                    y1 = pos[c][0].first;
                    x1 = pos[c][0].second;
                    y2 = pos[c][1].first;
                    x2 = pos[c][1].second;
                }
                else {
                    y2 = pos[c][0].first;
                    x2 = pos[c][0].second;
                    y1 = pos[c][1].first;
                    x1 = pos[c][1].second;
                }

                tmp2 = min(move_yx(tcy, tcx, y1, x1, board), move_xy(tcy, tcx, y1, x1, board_cpy)) + 1;
                tmp2 += (min(move_yx(y1, x1, y2, x2, board), move_xy(y1, x1, y2, x2, board_cpy)) + 1);

                if(result2 > tmp2) {
                    tcy = y2;
                    tcx = x2;
                    result2 = tmp2;
                }
            }
            cur_y = tcy;
            cur_x = tcx;
            board_cpy[pos[c][0].first][pos[c][0].second] = 0;
            board_cpy[pos[c][1].first][pos[c][1].second] = 0;
            tmp1 += result2;
        }
        if(result1 > tmp1) 
            result1 = tmp1;

        answer = min(answer, result1);
    } while(next_permutation(cards.begin(), cards.end()));
    


    return answer;
}