#include <bits/stdc++.h>
using namespace std;
int r, c, t;
int cnt = 0;
int visited[5][5];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char arr[5][5];
void dfs(int x, int y, int level) {
    if (level == t) {
        if (x == 0 && y == c) cnt++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > r || ny < 0 || ny > c || visited[nx][ny] || arr[nx][ny] == 'T') continue;
        visited[nx][ny] = 1;
        dfs(nx, ny, level + 1);
        visited[nx][ny] = 0;
    }
}
int main() {
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        scanf("%s", arr[i]);
    }
    r--, c--;
    visited[r][0] = 1;
    dfs(r, 0, 1);
    cout << cnt;
    return 0;
}