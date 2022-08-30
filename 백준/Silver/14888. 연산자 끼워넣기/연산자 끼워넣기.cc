#include <bits/stdc++.h>
using namespace std;
int n;
int arr[12];
int op[4];
long long maxx = LONG_LONG_MIN, minn = LONG_LONG_MAX;
void dfs(int level, long long res) {
    if (level >= n) {
        maxx = max(maxx, res);
        minn = min(minn, res);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i]) {
            op[i]--;
            if (i == 0)
                dfs(level + 1, res + arr[level]);
            else if (i == 1)
                dfs(level + 1, res - arr[level]);
            else if (i == 2)
                dfs(level + 1, res * arr[level]);
            else if (i == 3)
                dfs(level + 1, res / arr[level]);
            op[i]++;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    dfs(1, arr[0]);
    cout << maxx << '\n'
         << minn;

    return 0;
}