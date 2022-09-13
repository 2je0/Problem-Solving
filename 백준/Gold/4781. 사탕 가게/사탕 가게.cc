#include <bits/stdc++.h>
using namespace std;
int n, m, c, p;
double _m, _p;
int cal[10004];
int money[10004];
int dp[10004];

int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    while (1) {
        cin >> n >> _m;
        m = (100 * _m) + 0.5;
        if (n == 0 && m == 0) break;
        memset(dp, 0, sizeof(dp));
        int gmax = 0;
        for (int i = 0; i < n; i++) {
            cin >> c >> _p;
            p = (100 * _p) + 0.5;
            cal[i] = c, money[i] = p;
        }
        for (int i = 0; i <= m; i++) {
            int lmax = 0;
            for (int j = 0; j < n; j++) {
                if (i - money[j] >= 0) {
                    lmax = max(lmax, dp[i - money[j]] + cal[j]);
                }
            }
            dp[i] = lmax;
            gmax = max(lmax, gmax);
        }
        cout << gmax << '\n';
    }
    return 0;
}
