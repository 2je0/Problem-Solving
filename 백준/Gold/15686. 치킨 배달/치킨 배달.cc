#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m;
vector<pii> house;
vector<pii> chicken;
vector<int> dist;
int newDist[104];
int visited[54];
int distArr[104][17];
int minn = INT_MAX;

int distance(pii a, pii b) {
    int x = abs(a.first - b.first);
    int y = abs(a.second - b.second);
    return x + y;
}
void dfs(int now, int level) {
    if (level == m) {
        int sum = 0;
        for (int i = 0; i < house.size(); i++) {
            int houseMinDist = INT_MAX;
            for (int j = 0; j < chicken.size(); j++) {
                if (visited[j]) {
                    houseMinDist = min(houseMinDist, distArr[i][j]);
                }
            }
            sum += houseMinDist;
        }
        minn = min(minn, sum);
    } else {
        for (int i = now + 1; i < chicken.size(); i++) {
            if (!visited[i]) {
                visited[i] = 1;
                dfs(i, level + 1);
                visited[i] = 0;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            scanf("%d", &input);
            if (input == 1) house.push_back({i, j});
            if (input == 2) chicken.push_back({i, j});
        }
    }
    for (int i = 0; i < house.size(); i++) {
        for (int j = 0; j < chicken.size(); j++) {
            distArr[i][j] = distance(house[i], chicken[j]);
        }
    }
    dfs(-1, 0);
    printf("%d", minn);
    return 0;
}