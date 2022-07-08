#include <bits/stdc++.h>
#define MAX 104
using namespace std;
int m, n;
int arr[MAX][MAX];
int melt[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isFinish() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]) return false;
        }
    }
    return true;
}
void air(int time) {
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 || i == m - 1) && (j == 0 || j == n - 1)) {
                visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
            if (!arr[nx][ny]) {  //통로면 이동
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
            if (arr[nx][ny]) {
                melt[nx][ny] = time;
            }
        }
    }
}
void melting() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] && melt[i][j]) arr[i][j] = 0;
        }
    }
}
int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int time = 1;
    while (!isFinish()) {
        air(time++);
        melting();
    }
    int maxx = -1;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            maxx = max(maxx, melt[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (melt[i][j] == maxx) cnt++;
        }
    }
    cout << maxx << '\n'
         << cnt;
}