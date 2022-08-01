#include <bits/stdc++.h>
using namespace std;
int T, N, M;
int visited[1001];
vector<int> v[1001];
bool flag = true;
void dfs(int now, int before) {
    if (!flag) return;
    for (auto& nx : v[now]) {
        if (nx == before) continue;
        if (visited[nx]) {
            flag = false;
            return;
        }
        visited[nx] = 1;
        dfs(nx, now);
    }
}
void init() {
    memset(visited, 0, sizeof(visited));
    flag = true;
    for (int i = 1; i <= N; i++) {
        v[i].clear();
    }
}
int main() {
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &N, &M);
        int starter;
        while (M--) {
            int s, e;
            scanf("%d %d", &s, &e);
            starter = s;
            for (auto& ele : v[s]) {
                if (ele == e) {
                    flag = false;
                    break;
                }
            }
            v[s].push_back(e);
            v[e].push_back(s);
        }
        if (flag) {
            visited[starter] = 1;
            dfs(starter, -1);
            for (int i = 1; i <= N; i++) {
                if (!visited[i]) flag = false;
            }
        }

        if (!flag)
            printf("graph\n");
        else
            printf("tree\n");
    }
    return 0;
}