#include <bits/stdc++.h>
using namespace std;
int dp[1001][31];
int t, w, drop, maxx;
int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> t >> w;
    for (int i = 1; i <= t; i++) {
        cin >> drop;
        dp[i][0] = drop == 1 ? dp[i - 1][0] + 1 : dp[i - 1][0];
        for (int j = 1; j <= w; j++) {
            if (j > i) continue;
            if (drop == 1) {
                if (j & 1) {  // 홀수
                    dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
                } else {
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1);
                }
            } else if (drop == 2) {
                if (j & 1) {  // 홀수
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1);
                } else {
                    dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }
    }
    for (int i = 0; i <= w; i++) {
        maxx = max(maxx, dp[t][i]);
    }
    cout << maxx;
    return 0;
}
