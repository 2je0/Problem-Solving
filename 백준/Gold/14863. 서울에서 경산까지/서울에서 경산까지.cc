#include <bits/stdc++.h>
using namespace std;
long long dp[100001], n, k, sum;
int update[100001];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        long long wtime, wmoney, btime, bmoney;
        cin >> wtime >> wmoney >> btime >> bmoney;
        for (int j = k; j >= 0; j--) {
            long long maxx = 0;
            bool flag = false;
            if (j - wtime >= 0) {
                if (update[j - wtime] == i - 1) {
                    flag = true;
                    maxx = max(maxx, dp[j - wtime] + wmoney);
                }
            }
            if (j - btime >= 0) {
                if (update[j - btime] == i - 1) {
                    flag = true;
                    maxx = max(maxx, dp[j - btime] + bmoney);
                }
            }
            if (flag) {
                dp[j] = maxx;
                update[j] = i;
            }
        }
    }
    int ret = 0;
    for (int i = k; i >= 0; i--) {
        if (update[i] == n) {
            ret = dp[i];
            break;
        }
    }
    cout << ret;
    return 0;
}