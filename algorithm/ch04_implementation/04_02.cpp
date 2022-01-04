#include <iostream>
using namespace std;

int N, sol = 0;
int start_time = 0, end_time = 0;
int h, m, s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    end_time = N * 3600 + 59 * 60 + 59;

    for(int i = start_time; i <= end_time; i++) {
        h = i / 3600;
        m = (i % 3600) / 60;
        s = (i % 3600) % 60;

        if(h / 10 == 3 || h % 10 == 3) sol++;
        else if(m / 10 == 3 || m % 10 == 3) sol++;
        else if(s / 10 == 3 || s % 10 == 3) sol++;
    }

    cout << sol << '\n';

    return 0;
}