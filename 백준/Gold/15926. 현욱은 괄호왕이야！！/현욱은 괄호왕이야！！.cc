#include <bits/stdc++.h>
using namespace std;
int n, res = 0;
string str;
stack<int> st;
int main() {
    cin >> n;
    cin >> str;
    st.push(-1);
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            st.push(i);
            continue;
        }
        st.pop();
        if (st.size()) {
            res = max(res, i - st.top());
        } else {
            st.push(i);
        }
    }
    cout << res;

    return 0;
}