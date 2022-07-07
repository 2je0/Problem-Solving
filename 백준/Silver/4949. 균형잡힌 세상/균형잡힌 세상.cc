#include <bits/stdc++.h>
using namespace std;
bool isValid(string input) {
    stack<char> st;
    for (auto& ele : input) {
        if (ele == '(' || ele == '[')
            st.push(ele);
        else if (ele == ')') {
            if (st.empty()) return false;
            if (st.top() == '(')
                st.pop();
            else
                return false;
        } else if (ele == ']') {
            if (st.empty()) return false;
            if (st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}
int main() {
    while (1) {
        string input;
        getline(cin, input);
        if (input == ".") break;
        if (isValid(input))
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}