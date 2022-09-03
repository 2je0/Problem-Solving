#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
int n;
queue<int> q;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n;
    dp[n] = -1;
    q.push(n);
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x == 1) {
            break;
        }
        int _nx[] = {x / 2, x / 3, x - 1};
        bool boolnx[] = {(x % 2), (x % 3), 0};
        for (int i = 0; i < 3; i++) {
            int nx = _nx[i];
            if (boolnx[i] || nx < 1 || dp[nx]) continue;
            dp[nx] = x;
            q.push(nx);
        }
    }
    for (int i = 1; i != -1; i = dp[i]) {
        v.push_back(i);
    }
    cout << v.size() - 1 << '\n';
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }
    return 0;
}