#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;    //  초기 배열 세로(N), 가로(M), 연산 횟수(R)
int row, col;   //  현재 배열 세로(row), 가로(col)
vector<vector<int> > arr;
vector<vector<int> > v1;
vector<vector<int> > v2;
vector<vector<int> > v3;
vector<vector<int> > v4;

//  배열을 4등분함
void split_4() {
    v1.assign(row / 2, vector<int>(col / 2, 0));
    v2.assign(row / 2, vector<int>(col / 2, 0));
    v3.assign(row / 2, vector<int>(col / 2, 0));
    v4.assign(row / 2, vector<int>(col / 2, 0));

    for(int i = 0; i < row / 2; i++)
        for(int j = 0; j < col / 2; j++)
            v1[i][j] = arr[i][j];

    for(int i = 0; i < row / 2; i++)
        for(int j = col / 2; j < col; j++)
            v2[i][j - col / 2] = arr[i][j];

    for(int i = row / 2; i < row; i++) 
        for(int j = 0; j < col / 2; j++)
            v3[i - row / 2][j] = arr[i][j];

    for(int i = row / 2; i < row; i++) 
        for(int j = col / 2; j < col; j++)
            v4[i - row / 2][j - col / 2] = arr[i][j];
}

//  배열 상하 반전
void operate_1() {
    row = arr.size();
    col = arr[0].size();
    
    for(int i = 0; i < row / 2; i++) {
        for(int j = 0; j < col; j++)
            swap(arr[i][j], arr[row - i - 1][j]);
    }
}

//  배열 좌우 반전
void operate_2() {
    row = arr.size();
    col = arr[0].size();

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col / 2; j++)
            swap(arr[i][j], arr[i][col - j - 1]);
    }
}

//  배열 오른쪽으로 90도 회전
void operate_3() {
    row = arr.size();
    col = arr[0].size();

    vector<vector<int> > tmp(col, vector<int>(row, 0));

    for(int i = 0; i < col; i++) {
        for(int j = row - 1; j >= 0; j--)
            tmp[i][row - 1 - j] = arr[j][i];
    }

    tmp.swap(arr);
    vector<vector<int> >().swap(tmp);
}

//  배열 왼쪽으로 90도 회전
void operate_4() {
    row = arr.size();
    col = arr[0].size();

    vector<vector<int> > tmp(col, vector<int>(row, 0));

    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++)
            tmp[col - 1 - i][j] = arr[j][i];
    }

    tmp.swap(arr);
    vector<vector<int> >().swap(tmp);
}

void operate_5() {
    row = arr.size();
    col = arr[0].size();

    split_4();

    for(int i = 0; i < row / 2; i++)
        for(int j = 0; j < col / 2; j++)
            arr[i][j] = v3[i][j];
    
    for(int i = 0; i < row / 2; i++)
        for(int j = col / 2; j < col; j++)
            arr[i][j] = v1[i][j - col / 2];
    
    for(int i = row / 2; i < row; i++)
        for(int j = 0; j < col / 2; j++)
            arr[i][j] = v4[i - row / 2][j];
    
    for(int i = row / 2; i < row; i++)
        for(int j = col / 2; j < col; j++)
            arr[i][j] = v2[i - row / 2][j - col / 2];

    vector<vector<int> >().swap(v1);
    vector<vector<int> >().swap(v2);
    vector<vector<int> >().swap(v3);
    vector<vector<int> >().swap(v4);
}

void operate_6() {
    row = arr.size();
    col = arr[0].size();

    split_4();

    for(int i = 0; i < row / 2; i++)
        for(int j = 0; j < col / 2; j++)
            arr[i][j] = v2[i][j];
    
    for(int i = 0; i < row / 2; i++)
        for(int j = col / 2; j < col; j++)
            arr[i][j] = v4[i][j - col / 2];
    
    for(int i = row / 2; i < row; i++)
        for(int j = 0; j < col / 2; j++)
            arr[i][j] = v1[i - row / 2][j];
    
    for(int i = row / 2; i < row; i++)
        for(int j = col / 2; j < col; j++)
            arr[i][j] = v3[i - row / 2][j - col / 2];

    vector<vector<int> >().swap(v1);
    vector<vector<int> >().swap(v2);
    vector<vector<int> >().swap(v3);
    vector<vector<int> >().swap(v4);
}

void operate(int opt) {
    if(opt == 1)
        operate_1();
    else if(opt == 2)
        operate_2();
    else if(opt == 3)
        operate_3();
    else if(opt == 4)
        operate_4();
    if(opt == 5)
        operate_5();
    else if(opt == 6)
        operate_6();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> R;

    arr.assign(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];
    }

    for(int i = 0; i < R; i++) {
        int opt;
        cin >> opt;

        operate(opt);
    }

    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}