#include <iostream>
using namespace std;

long long f[100] = {0, };

long long fibo(int x) {
    if(x == 1 || x == 2)
        return f[x];
    
    else {
        for(int i = 3; i <= x; i++)
            f[i] = f[i - 1] + f[i - 2];
    }

    return f[x];
}

int main(void) {
    f[1] = 1;
    f[2] = 1;

    cout << fibo(90) << '\n';
    return 0;
}