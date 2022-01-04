#include <iostream>
using namespace std;

void recursive_function(int i) {
    if(i == 100) return;

    cout << i << "번째 재귀 함수에서 " << i + 1 << "번째 재귀 함수를 호출합니다.\n";
    recursive_function(i + 1); 
    cout << i << "번쨰 재귀 함수를 종료합니다.\n";
}

int main(void) {
    recursive_function(1);
    return 0;
}