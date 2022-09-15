#include <bits/stdc++.h>
using namespace std;
int n;
int dp[101];
int L[21], J[21];

int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> J[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 100; j >= L[i]; j--) {
            dp[j] = max(dp[j], dp[j - L[i]] + J[i]);
        }
    }
    cout << dp[99];
    return 0;
}
