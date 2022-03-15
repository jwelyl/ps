#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define MAXNUM  100001
#define NONE        -1
#define SUB          0
#define ADD          1
#define MUL          2

using namespace std;

int N, K;
int level = 0;
vector<bool> visited(MAXNUM, false);
vector<int> parents(MAXNUM, NONE);
stack<int> path;

void bfs() {
    queue<int> q;
    int num = 1;
    visited[N] = true;
    q.push(N);

    while(!q.empty()) {
        int tmp = 0;

        for(int i = 0; i < num; i++) {
            int cur = q.front();
            q.pop();

            for(int j = 0; j < 3; j++) {
                int next;
                
                if(j == SUB)
                    next = cur - 1;
                else if(j == ADD)
                    next = cur + 1;
                else if(j == MUL)
                    next = cur * 2;

                if(0 <= next && next < MAXNUM && !visited[next]) {
                    parents[next] = cur;
                    visited[next] = true;

                    if(next == K) { //  목적지 찾은 경우
                        level++;
                        // cout << "목적지 찾음\n";
                        return;
                    }

                    tmp++;
                    // cout << next << " 삽입\n";
                    q.push(next);
                }
            }
        }

        if(tmp > 0) level++;    //  다음 층에 1개라도 있을 경우 level 1 증가
        num = tmp;
    }

    // cout << "목적지 찾지 못함\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    if(N != K)
        bfs();

    // for(int i = 0; i < 32; i++)
    //     cout << parents[i] << ' ';
    // cout << '\n';


    cout << level << '\n';

    int pos = K;
    while(pos != NONE) {
        path.push(pos);
        pos = parents[pos];
    }

    while(!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << '\n';

    return 0;
}