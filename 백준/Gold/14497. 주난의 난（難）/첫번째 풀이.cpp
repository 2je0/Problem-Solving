#include <bits/stdc++.h>
#define MAX 300
using namespace std;
string arr[MAX];
int visited[MAX][MAX];
vector<pair<int, int>> v;
int n, m;
int x1, y_1, x2, y2;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int res = 0;

int isFind() {
    res++;
    memset(visited, 0, sizeof(visited));
    v.clear();
    queue<pair<int, int>> q;
    q.push({x1, y_1});
    visited[x1][y_1] = 1;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        if (x == x2 && y == y2) return res;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny]) continue;

            if (arr[nx][ny] == '1') {
                v.push_back({nx, ny});
            } else {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    for (auto& ele : v) {
        arr[ele.first][ele.second] = '0';
    }
    return 0;
}

int main() {
    cin >> n >> m >> x1 >> y_1 >> x2 >> y2;
    x1--;
    y_1--;
    x2--;
    y2--;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while (1) {
        int finish = isFind();
        if (finish) {
            cout << finish;
            break;
        }
    }
    return 0;
}
