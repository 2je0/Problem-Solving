#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
int visited[100004];
int minLevel = INT_MAX;
int cnt = 0;
int main() {
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> q;
    q.push({n, 0});
    while (!q.empty()) {
        int x, level;
        tie(x, level) = q.front();
        q.pop();
        visited[x] = 1;
        // cout << x << " " << level << endl;
        if (x == k) {
            cnt++;
            minLevel = level;
        }
        if (level > minLevel) break;

        int nx[3] = {x - 1, x + 1, 2 * x};
        for (int i = 0; i < 3; i++) {
            if (nx[i] < 0 || nx[i] > 100000 || visited[nx[i]]) continue;
            q.push({nx[i], level + 1});
        }
    }
    cout << minLevel << '\n'
         << cnt;
    return 0;
}