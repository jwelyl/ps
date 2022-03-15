#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#define MAXD    987654321
using namespace std;

int N, M;
int result = MAXD;
vector<vector<int> > graph;
vector<pair<int, int> > homes;      //  집들의 좌표
vector<pair<int, int> > chickens;   //  치킨집들의 좌표
vector<bool> tmp;

int m_dist(int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2);
}

int chicken_dist(int idx, vector<pair<int, int> > chicks) { //  idx번째 집에서 가장 가까운 치킨집 거리 반환
    int min_dist = MAXD;
    int hy = homes[idx].first;
    int hx = homes[idx].second;

    for(int i = 0; i < chicks.size(); i++) 
        min_dist = min(min_dist, m_dist(hy, hx, chicks[i].first, chicks[i].second));
    
    return min_dist;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    graph.assign(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int x;
            cin >> x;

            graph[i][j] = x;
            if(x == 1)
                homes.push_back(make_pair(i, j));
            else if(x == 2)
                chickens.push_back(make_pair(i, j));
        }
    }
    // cout << "집 개수 : " << homes.size() << '\n';
    // cout << "치킨집 개수 : " << chickens.size() << '\n';

    tmp.assign(chickens.size(), true);
    for(int i = 0; i < M; i++)
        tmp[i] = false;

    // int cnt = 0;
    do {
        int tmp_result = 0;
        // cnt++;
        vector<pair<int, int> > survived;   //  폐업하지 않은 치킨집
        for(int i = 0; i < tmp.size(); i++) {
            if(tmp[i] == false)
                survived.push_back(chickens[i]);
        }

        for(int i = 0; i < homes.size(); i++)
            tmp_result += chicken_dist(i, survived);

        if(tmp_result < result)
            result = tmp_result;
    } while(next_permutation(tmp.begin(), tmp.end()));
    // cout << "경우의 수 : " << cnt << '\n';

    cout << result << '\n';
    return 0;
}