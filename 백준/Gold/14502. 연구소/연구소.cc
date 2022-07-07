#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[8][8];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<pair<int, int>> zero;
vector<pair<int, int>> two;
int findMaxArea(pair<int, int> i, pair<int, int> j, pair<int, int> k) {
    int arrCopy[8][8];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arrCopy[i][j] = arr[i][j];
        }
    }
    arrCopy[i.first][i.second] = 1;
    arrCopy[j.first][j.second] = 1;
    arrCopy[k.first][k.second] = 1;
    int visited[8][8] = {
        0,
    };
    queue<pair<int, int>> q;
    for (auto& ele : two) {
        visited[ele.first][ele.second] = 1;
        q.push(ele);
    }
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;
            if (!arrCopy[nx][ny]) {
                visited[nx][ny] = 1;
                arrCopy[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!arrCopy[i][j]) ret++;
        }
    }
    return ret;
}
int main() {
    int maxx = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) zero.push_back({i, j});
            if (arr[i][j] == 2) two.push_back({i, j});
        }
    }
    for (int i = 0; i < zero.size() - 2; i++) {
        for (int j = i + 1; j < zero.size() - 1; j++) {
            for (int k = j + 1; k < zero.size(); k++) {
                int area = findMaxArea(zero[i], zero[j], zero[k]);
                maxx = max(area, maxx);
            }
        }
    }
    cout << maxx;
}