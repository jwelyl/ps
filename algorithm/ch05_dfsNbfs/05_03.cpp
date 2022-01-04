#include <iostream>
using namespace std;

void recursive_function() {
    cout << "재귀 함수를 호출합니다.\n";
    recursive_function(); 
}

int main(void) {
    recursive_function();
    return 0;
}