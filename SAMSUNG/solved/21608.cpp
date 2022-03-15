#include <iostream>
#include <vector>
#include <cstdlib>
#define NONE        0
#define ZERO        0
#define ONE         1
#define TWO        10
#define THREE     100
#define FOUR     1000
using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int N;
int ans = 0;
vector<vector<int> > graph;
vector<vector<int> > favor;

//  (y, x)에 num이 있을 때 (y, x) 인접 칸에 num이 좋아하는 친구 수
int num_of_friends(int y, int x, int num) {
    int ret = 0;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny <= 0 || nx <= 0 || ny > N || nx > N)
            continue;

        for(int j = 0; j < favor[num].size(); j++) {
            if(graph[ny][nx] == favor[num][j]) {
                ret++;
                break;
            }
        }
    }

    if(ret < 0 || ret > 4) {
        cout << "something was wrong in func num_of_friends\n";
        exit(-1);
    }

    return ret;
}

//  (y, x)의 인접한 칸 중 빈 칸의 개수
int num_of_empty(int y, int x) {
    int ret = 0;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny <= 0 || nx <= 0 || ny > N || nx > N)
            continue;

        if(graph[ny][nx] == NONE)
            ret += 1;
    }

    if(ret < 0 || ret > 4) {
        cout << "something was wrong in func num_of_empty\n";
        exit(-1);
    }

    return ret;
}

//  num 학생 좌석 배치
void set_pos(int num) {
    int res_y = -1;          //  최종 배치할 행
    int res_x = -1;          //  최종 배치할 열
    int res_f = -1;      //  최종 배치할 때 인접 친구 수
    int res_e = -1;      //  최종 배치할 때 인접 빈칸 수

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(graph[i][j] != NONE) continue;   //  이미 배정된 좌석의 경우 skip

            int tmp_f = num_of_friends(i, j, num);
            int tmp_e = num_of_empty(i, j);

            if(res_f < tmp_f) { //  인접한 친구가 더 많을 경우
                res_f = tmp_f;
                res_e = tmp_e;
                res_y = i;
                res_x = j;
            }
            else if(res_f == tmp_f && res_e < tmp_e) {  //  인접한 친구 수는 적지만 빈 칸이 더 많을 경우
                res_e = tmp_e;
                res_y = i;
                res_x = j;
            }
        }
    }

    if(!(1 <= res_y && res_y <= N && 1 <= res_x && res_x <= N)) {
        cout << "something was wrong in func set_pos\n";
        exit(-1);
    }

    graph[res_y][res_x] = num;
    // cout << "학생 num이 배치된 위치 : (" << res_y << ", " << res_x << ")\n"; 
}

//  모든 자리 배치 끝난 후 만족도 조사
void calc_ans() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int num = num_of_friends(i, j, graph[i][j]);

            if(num == 0)
                ans += ZERO;
            else if(num == 1)
                ans += ONE;
            else if(num == 2)
                ans += TWO;
            else if(num == 3)
                ans += THREE;
            else if(num == 4)
                ans += FOUR;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    graph.assign(N + 1, vector<int>(N + 1, NONE));
    favor.assign((N * N + 1), vector<int>());

    for(int i = 1; i <= N * N; i++) {
        int num;
        cin >> num;
        // cout << "현재 배치하려는 학생 번호 : " << num << '\n';

        for(int j = 0; j < 4; j++) {
            int f;
            cin >> f;
            favor[num].push_back(f);
        }

        // for(int j = 0; j < favor[num].size(); j++)
        //     cout << favor[num][j] << ' ';
        // cout << '\n';

        if(favor[num].size() != 4) {
            cout << "something was wrong in input\n";
            exit(-1);
        }

        set_pos(num);
    }

    // for(int i = 1; i <= N * N; i++) {
    //     cout << i << " : ";
    //     for(int j = 0; j < favor[i].size(); i++)
    //         cout << favor[i][j] << ' ';
    //     cout << '\n';
    // }

    calc_ans();
    cout << ans << "\n";

    return 0;
}