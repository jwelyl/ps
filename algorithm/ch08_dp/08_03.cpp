#include <iostream>
using namespace std;

long long f[100] = {0, };

long long fibo(int x) {
    cout << "fibo(" << x << ")\n";
    if(x == 1 || x == 2)
        return 1;
    if(f[x] != 0)
        return f[x];
    else {
        f[x] = fibo(x - 1) + fibo(x - 2);
        return f[x];
    }
}

int main(void) {
    cout << fibo(6) << '\n';
    return 0;
}