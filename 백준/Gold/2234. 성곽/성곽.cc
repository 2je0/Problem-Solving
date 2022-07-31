#include <bits/stdc++.h>
using namespace std;
int m, n;
int arr[50][50];
int visited[50][50];

int maxx = -1;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int sectionNum = 1;
vector<int>
    room;
int dfs(int x, int y) {
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (arr[x][y] & (1 << i) || visited[nx][ny]) continue;
        visited[nx][ny] = sectionNum;
        cnt += dfs(nx, ny);
    }
    return cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            visited[i][j] = sectionNum;
            room.push_back(dfs(i, j));
            sectionNum++;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n || visited[i][j] == visited[ni][nj]) continue;
                int sum = room[visited[i][j] - 1] + room[visited[ni][nj] - 1];
                maxx = max(maxx, sum);
            }
        }
    }
    sort(room.begin(), room.end(), greater<int>());
    cout << room.size() << '\n'
         << room[0] << '\n'
         << maxx;
    return 0;
}