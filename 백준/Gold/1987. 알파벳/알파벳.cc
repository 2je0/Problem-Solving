#include <bits/stdc++.h>
using namespace std;
char arr[20][20];
int alpha[26];
int visited[20][20];

int r, c;
int maxx = -1;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int depth) {
    maxx = max(maxx, depth);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]) continue;
        int alphaIdx = arr[nx][ny] - 'A';
        if (alpha[alphaIdx]) continue;
        visited[nx][ny] = 1;
        alpha[alphaIdx] = 1;
        dfs(nx, ny, depth + 1);
        visited[nx][ny] = 0;
        alpha[alphaIdx] = 0;
    }
}
int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        scanf("%s", arr[i]);
    }
    visited[0][0] = 1;
    int alphaIdx = arr[0][0] - 'A';
    alpha[alphaIdx] = 1;
    dfs(0, 0, 1);
    printf("%d", maxx);

    return 0;
}