#include <bits/stdc++.h>
#define MAXN 1000004
using namespace std;
int arr[MAXN];
int main() {
    int n;
    cin >> n;
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int input;
        scanf("%d", &input);
        if (st.empty()) {
            st.push({input, i});
        } else {
            while (!st.empty()) {
                int top = st.top().first;
                if (top < input) {
                    arr[st.top().second] = input;
                    st.pop();
                } else
                    break;
            }
            st.push({input, i});
        }
    }
    while (!st.empty()) {
        arr[st.top().second] = -1;
        st.pop();
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}