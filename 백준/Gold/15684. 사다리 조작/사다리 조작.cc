#include <bits/stdc++.h>
using namespace std;
int N, M, H;
int arr[34][12];
int res = 5;
bool simul() {
    for (int i = 1; i <= N; i++) {
        int depth = 0;
        int idx = i;
        while (depth <= H) {
            int point = arr[depth][idx];
            if (point == 1)
                idx++;
            else if (point == 2)
                idx--;
            depth++;
        }
        if (idx != i) return false;
    }
    return true;
}
void dfs(int hn, int level) {
    if (level >= res || level > 3) return;
    int h = hn / 100;
    int n = hn % 100;
    if (hn == H * 100 + N) {
        if (simul()) {
            res = min(level, res);
        }
        return;
    }
    int nh = n < N ? h : h + 1;
    int nn = n < N ? n + 1 : 1;

    dfs(nh * 100 + nn, level);
    if (n < N && !arr[h][n] && !arr[h][n + 1] && level < 3) {
        arr[h][n] = 1, arr[h][n + 1] = 2;
        dfs(nh * 100 + nn, level + 1);
        arr[h][n] = 0, arr[h][n + 1] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[x][y + 1] = 2;
    }
    dfs(101, 0);
    if (res == 5)
        cout << -1;
    else
        cout << res;
    return 0;
}