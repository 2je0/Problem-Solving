#include <bits/stdc++.h>
using namespace std;

int n;
int arr[11][11];
int price[11][11];
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
int minn = INT_MAX;

void calcPrice(int x, int y) {
    int res = 0;
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        res += arr[nx][ny];
    }
    price[x][y] = res;
}

void dfs(int x, int y, int level, int sum) {
    if (level == 3) {
        minn = min(minn, sum);
    }
    for (int i = x; i < n - 1; i++) {
        for (int j = y; j < n - 1; j++) {
            if (i - x + j - y < 3) continue;
            dfs(i, j, level + 1, sum + price[i][j]);
        }
    }
}
void dfss(vector<pair<int, int>> v, int sum) {
    if (v.size() == 3) {
        minn = min(minn, sum);
        return;
    }
    int x = v.back().first;
    int y = v.back().second;
    for (int i = x; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            bool skip = false;
            for (auto& ele : v) {
                if (abs(i - ele.first) + abs(j - ele.second) < 3) {
                    skip = true;
                    break;
                }
            }
            if (skip) continue;
            v.push_back({i, j});
            // for (auto& ele : v) {
            //     cout << ele.first << ',' << ele.second << endl;
            // }
            // cout << endl;
            dfss(v, sum + price[i][j]);
            v.pop_back();
        }
    }
}
int main() {
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            calcPrice(i, j);
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            v.push_back({i, j});
            dfss(v, price[i][j]);
            v.pop_back();
        }
    }
    // for (int i = 1; i < n - 1; i++) {
    //     for (int j = 1; j < n - 1; j++) {
    //         printf("%4d", price[i][j]);
    //     }
    //     cout << endl;
    // }
    cout << minn;

    return 0;
}