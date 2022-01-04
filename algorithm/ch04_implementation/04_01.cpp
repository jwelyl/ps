#include <iostream>
#include <string>
using namespace std;

int N, ypos = 1, xpos = 1;
string plan;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin.ignore();
    getline(cin, plan);
    cout << plan << '\n';
    
    for(int i = 0; i < plan.size(); i++) {
       for(int j = 0; j < 4; j++) {
           if(dir[j] == plan[i]) {
               int ny = ypos + dy[j];
               int nx = xpos + dx[j];

               if(ny < 1 || ny > N || nx < 1 || nx > N) continue;
               ypos = ny;
               xpos = nx;
           }
       }
    }

    cout << ypos << " " << xpos << '\n';

    return 0;
}