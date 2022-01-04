#include <iostream>
#include <string>
using namespace std;

string pos;
int sol = 0, ypos, xpos;
int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> pos;
    xpos = pos[0] - 'a' + 1;
    ypos = pos[1] - '0';
    // cout << "ypos = " << ypos << '\n';

    for(int i = 0; i < 8; i++) {
        int ny = ypos + dy[i];
        int nx = xpos + dx[i];

        // cout << "(" << nx << ", " << ny << ")" << '\n';

        if(!(ny < 1 || ny > 8 || nx < 1 || nx > 8))
            sol++;
    }

    cout << sol << '\n';
    return 0;
}