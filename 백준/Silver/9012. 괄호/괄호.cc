#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        stack<char> st;
        string input;
        cin >> input;
        bool valid = true;
        for (auto& ele : input) {
            if (ele == '(')
                st.push(ele);
            else {
                if (st.empty()) {
                    valid = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        if (valid && !st.empty()) valid = false;
        if (valid)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}