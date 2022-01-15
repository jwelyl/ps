// https://programmers.co.kr/learn/courses/30/lessons/60063
#include <string>
#include <vector>

using namespace std;

int N;
int hy, hx;
int ty, tx;

bool cant_move(int y1, int x1, int y2, int x2, vector<vector<int> > board) {
    return (y1 < 0 || y1 >= N || x1 < 0 || x1 >= N || y2 < 0 || y2 >= N || x2 < 0 || x2 >= N || board[y1][x1] == 1 || board[y2][x2] == 1);
}

bool move_left(vector<vector<int> > board) {
    if(cant_move(hy, hx - 1, ty, tx - 1, board)) return false;

    hx -= 1;
    tx -= 1;
    return true;
}

bool move_right(vector<vector<int> > board) {
    if(cant_move(hy, hx + 1, ty, tx + 1, board)) return false;

    hx += 1;
    tx += 1;
    return true;
}

bool move_up(vector<vector<int> > board) {
    if(cant_move(hy - 1, hx, ty - 1, tx, board)) return false;

    hy -= 1;
    ty -= 1;
    return true;
}

bool move_down(vector<vector<int> > board) {
    if(cant_move(hy + 1, hx, ty + 1, tx, board)) return false;

    hy += 1;
    ty += 1;
    return true;
}

bool turn_cw_head(vector<vector<int> > board) { //  head가 시계 방향 회전(tail 축)
    if(hy < ty) {
        if(cant_move(ty, tx + 1, ty, tx, board)) return false;
        if(board[hy][hx + 1] == 1) return false;

        hy = ty;
        hx = tx + 1;
        return true;
    }
    if(hx > tx) {
        if(cant_move(ty + 1, tx, ty, tx, board)) return false;
        if(board[hy + 1][hx] == 1) return false;

        hy = ty + 1;
        hx = tx;
        return true;
    }
    if(hy > ty) {
        if(cant_move(ty, tx - 1, ty, tx, board)) return false;
        if(board[hy][hx - 1] == 1) return false;

        hy = ty;
        hx = tx - 1;
        return true;
    }
    if(hx < tx) {
        if(cant_move(ty - 1, tx, ty, tx, board)) return false;
        if(board[hy - 1][hx] == 1) return false;

        hy = ty - 1;
        hx = tx;
        return true;
    }
}

bool turn_cw_tail(vector<vector<int> > board) { //  tail이 시계 방향 회전(head 축)
    if(hy > ty) {
        // if(cant_move(ty, tx + 1, ty, tx, board)) return false;
        if(cant_move(hy, hx, hy, hx + 1, board)) return false;
        // if(board[hy][hx + 1] == 1) return false;
        if(board[ty][tx + 1] == 1) return false;

        // hy = ty;
        ty = hy;
        // hx = tx + 1;
        tx = hx + 1;
        return true;
    }
    if(hx < tx) {
        // if(cant_move(ty + 1, tx, ty, tx, board)) return false;
        if(cant_move(hy, hx, hy + 1, hx, board)) return false;
        // if(board[hy + 1][hx] == 1) return false;
        if(board[ty + 1][tx] == 1) return false;

        // hy = ty + 1;
        ty = hy + 1;
        // hx = tx;
        tx = hx;

        return true;
    }
    if(hy < ty) {
        // if(cant_move(ty, tx - 1, ty, tx, board)) return false;
        if(cant_move(hy, hx, hy, hx - 1, board)) return false;
        // if(board[hy][hx - 1] == 1) return false;
        if(board[ty][tx - 1] == 1) return false;

        ty = hy;
        tx = hx - 1;
        return true;
    }
    if(hx > tx) {
        // if(cant_move(ty - 1, tx, ty, tx, board)) return false;
        if(cant_move(hy, hx, hy - 1, hx, board)) return false;
        if(board[ty - 1][tx] == 1) return false;

        ty = hy - 1;
        tx = hx;
        return true;
    }
}



bool turn_ccw_head(vector<vector<int> > board) { //  head가 반시계 방향 회전(tail 축)
    if(hy < ty) {
        if(cant_move(ty, tx - 1, ty, tx, board)) return false;
        if(board[hy][hx - 1] == 1) return false;

        hy = ty;
        hx = tx - 1;
        return true;
    }
    if(hx > tx) {
        if(cant_move(ty - 1, tx, ty, tx, board)) return false;
        if(board[hy - 1][hx] == 1) return false;

        hy = ty - 1;
        hx = tx;
        return true;
    }
    if(hy > ty) {
        if(cant_move(ty, tx + 1, ty, tx, board)) return false;
        if(board[hy][hx + 1] == 1) return false;

        hy = ty;
        hx = tx + 1;
        return true;
    }
    if(hx < tx) {
        if(cant_move(ty + 1, tx, ty, tx, board)) return false;
        if(board[hy + 1][hx] == 1) return false;

        hy = ty + 1;
        hx = tx;
        return true;
    }
}

bool turn_ccw_tail(vector<vector<int> > board) { //  tail가 반시계 방향 회전(head 축)
    if(hy > ty) {
        // if(cant_move(ty, tx - 1, ty, tx, board)) return false;
        if(cant_move(hy, hx, hy, hx - 1, board)) return false;
        // if(board[hy][hx - 1] == 1) return false;
        if(board[ty][tx - 1] == 1) return false;

        ty = hy;
        tx = hx - 1;
        return true;
    }
    if(hx < tx) {
        // if(cant_move(ty - 1, tx, ty, tx, board)) return false;
        if(cant_move(hy, hx, hy - 1, hx, board)) return false;
        // if(board[hy - 1][hx] == 1) return false;
        if(board[ty - 1][tx] == 1) return false;

        ty = hy - 1;
        tx = hx;
        return true;
    }
    if(hy < ty) {
        // if(cant_move(ty, tx + 1, ty, tx, board)) return false;
        if(cant_move(hy, hx, hy, hx + 1, board)) return false;
        if(board[ty][tx + 1] == 1) return false;

        ty = hy;
        tx = hx + 1;
        return true;
    }
    if(hx > tx) {
        // if(cant_move(ty + 1, tx, ty, tx, board)) return false;
        if(cant_move(hy, hx, hy + 1, hx, board)) return false;
        if(board[ty + 1][tx] == 1) return false;

        ty = hy + 1;
        tx = hx;
        return true;
    }
}


int solution(vector<vector<int> > board) {
    int answer = 0;
    return answer;
}