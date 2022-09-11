#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[10001];
int main() {
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        if (temp > 10000) continue;
        for (int j = temp; j <= k; j++) {
            dp[j] += dp[j - temp];
        }
    }
    cout << dp[k];
    return 0;
}