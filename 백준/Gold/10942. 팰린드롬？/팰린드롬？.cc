#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[2001];
bool dp[2001][2001];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (i == j)
                dp[i][j] = 1;
            else if (j == i - 1)
                dp[i][j] = (arr[i] == arr[j]);
            else {
                dp[i][j] = dp[i - 1][j + 1] && arr[i] == arr[j];
            }
        }
    }
    cin >> m;
    for (int i = 0, s, e; i < m; i++) {
        cin >> s >> e;
        cout << dp[e - 1][s - 1] << '\n';
    }
    return 0;
}