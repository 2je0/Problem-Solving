#include <bits/stdc++.h>
using namespace std;
#define MAXN 17
int n, wall[MAXN][MAXN];
long long cnt[MAXN][MAXN][3];
int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n;
    cnt[1][2][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> wall[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (wall[i][j]) {
                continue;
            }
            if (j > 1) {
                cnt[i][j][0] += cnt[i][j - 1][0];
                cnt[i][j][0] += cnt[i][j - 1][2];
            }
            if (i > 1) {
                cnt[i][j][1] += cnt[i - 1][j][1];
                cnt[i][j][1] += cnt[i - 1][j][2];
            }
            if (i > 1 && j > 1 && wall[i - 1][j] == 0 && wall[i][j - 1] == 0) {
                cnt[i][j][2] += cnt[i - 1][j - 1][0];
                cnt[i][j][2] += cnt[i - 1][j - 1][1];
                cnt[i][j][2] += cnt[i - 1][j - 1][2];
            }
        }
    }
    cout << cnt[n][n][0] + cnt[n][n][1] + cnt[n][n][2];
    return 0;
}
