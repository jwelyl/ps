#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int main(void) {
    st.push(5);
    st.push(2);
    st.push(3);
    st.push(7);
    st.pop();
    st.push(1);
    st.push(4);
    st.pop();

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';

    return 0;
}