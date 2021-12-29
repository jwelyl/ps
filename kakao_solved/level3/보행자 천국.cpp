// https://programmers.co.kr/learn/courses/30/lessons/1832
#include <vector>

using namespace std;

int MOD = 20170805;

vector<vector<int> > horiz;
vector<vector<int> > vert;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    horiz.assign(m + 1, vector<int>());
    vert.assign(m + 1, vector<int>());

    for(int i = 0; i <= m; i++) {
        horiz[i].assign(n + 1, 0);
        vert[i].assign(n + 1, 0);
    }

    horiz[1][1] = 1;
    vert[1][1] = 1;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(city_map[i - 1][j - 1] == 0) {
                horiz[i][j] = (horiz[i][j] + vert[i - 1][j] + horiz[i][j - 1]) % MOD;
                vert[i][j] = (vert[i][j] + vert[i - 1][j] + horiz[i][j - 1]) % MOD;
            }
            else if(city_map[i - 1][j - 1] == 1) {
                horiz[i][j] = 0;
                vert[i][j] = 0;
            }
            else if(city_map[i - 1][j - 1] == 2) {
                horiz[i][j] = horiz[i][j - 1];
                vert[i][j] = vert[i - 1][j];
            }
        }
    }

    answer = (horiz[m][n - 1] + vert[m - 1][n]) % MOD;
    return answer;
}