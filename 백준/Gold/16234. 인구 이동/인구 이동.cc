#include <bits/stdc++.h>
#define MAXN 54
using namespace std;

int n, l, r;
int arr[MAXN][MAXN];
int visited[MAXN][MAXN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<vector<pair<int, int>>> vindex;
vector<int> mean;
bool isFinish = false;
int cnt = 0;

void openBorder(int x, int y) {
    vector<pair<int, int>> v;
    int totalPeople = 0;
    int numOfNation = 0;
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    q.push({x, y});
    while (!q.empty()) {
        int nowx, nowy;
        tie(nowx, nowy) = q.front();
        q.pop();
        totalPeople += arr[nowx][nowy];
        numOfNation++;
        v.push_back({nowx, nowy});
        for (int i = 0; i < 4; i++) {
            int nx = nowx + dx[i];
            int ny = nowy + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) continue;
            if (abs(arr[nowx][nowy] - arr[nx][ny]) >= l && abs(arr[nowx][nowy] - arr[nx][ny]) <= r) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    mean.push_back(totalPeople / numOfNation);
    vindex.push_back(v);
}
void move() {
    isFinish = true;
    for (int i = 0; i < mean.size(); i++) {
        for (auto& v : vindex[i]) {
            if (arr[v.first][v.second] != mean[i]) {
                arr[v.first][v.second] = mean[i];
                isFinish = false;
            }
        }
    }
    vindex.clear();
    mean.clear();
    if (!isFinish)
        cnt++;
}
int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    while (1) {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    openBorder(i, j);
                }
            }
        }
        if (!mean.size()) break;
        move();
        if (isFinish) break;
    }
    cout << cnt;
    return 0;
}