#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;  // 30

    // Pop elements
    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 20

    // Check if empty
    if (st.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    cout << "Stack size: " << st.size() << endl; // 2
    return 0;
}
