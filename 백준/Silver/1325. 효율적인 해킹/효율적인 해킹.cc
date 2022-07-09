#include <bits/stdc++.h>
#define MAXN 10004
#define MAXM 100004
using namespace std;
int n, m;
vector<int> g[MAXN];
int memo[MAXN];
int visited[MAXN];

int dfs(int k) {
    int res = 1;
    for (auto& ele : g[k]) {
        if (!visited[ele]) {
            visited[ele] = 1;
            res += dfs(ele);
        }
    }
    // memo[k] = res;
    return res;
}
int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int f, t;
        scanf("%d %d", &t, &f);
        g[f].push_back(t);
    }
    int maxx = -1;
    for (int i = 1; i <= n; i++) {
        // if (!memo[i]) {
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        int hack = dfs(i);
        memo[i] = hack;
        // }
        maxx = max(memo[i], maxx);
    }
    for (int i = 1; i <= n; i++) {
        if (memo[i] == maxx) printf("%d ", i);
    }
    return 0;
}