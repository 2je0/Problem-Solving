#include <bits/stdc++.h>
using namespace std;
int N;
int people[10];
vector<int> graph[10];
int visited[10];
int total = 0, minn = 98765432;
void dfs(int now, int status) {
    for (auto& nx : graph[now]) {
        int nRes = status & (1 << now) ? 1 : 0;
        int nxRes = status & (1 << nx) ? 1 : 0;
        if (visited[nx] || (nRes ^ nxRes)) continue;
        visited[nx] = 1;
        dfs(nx, status);
    }
}

int isTwoRegion(int status) {
    int zero = -1, one = -1, idx = 0, sum = 0;
    bool flag = false;
    while (zero == -1 || one == -1) {
        if (status & (1 << idx))
            one = idx;
        else
            zero = idx;
        idx++;
    }
    memset(visited, 0, sizeof(visited));
    visited[one] = 1;
    dfs(one, status);
    for (int i = 0; i < N; i++) {
        int temp = (status & (1 << i)) ? 1 : 0;
        if (temp ^ visited[i]) return 0;
    }

    memset(visited, 0, sizeof(visited));
    visited[zero] = 1;
    dfs(zero, status);
    for (int i = 0; i < N; i++) {
        int temp = (status & (1 << i)) ? 0 : 1;
        if (temp ^ visited[i]) return 0;
    }
    for (int i = 0; i < N; i++) {
        if (status & (1 << i)) sum += people[i];
    }
    return sum;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &people[i]);
        total += people[i];
    }
    for (int i = 0, input; i < N; i++) {
        scanf("%d", &input);
        for (int j = 0, to; j < input; j++) {
            scanf("%d", &to);
            graph[i].push_back(to - 1);
        }
    }
    for (int i = 1; i < (1 << N) - 1; i++) {
        int res = isTwoRegion(i);
        // cout << i << ' ' << res << ' ' << minn << endl;
        if (res) {
            int counterRes = total - res;
            minn = min(abs(res - counterRes), minn);
            // cout << i << ' ' << res << ' ' << minn << endl;
        }
    }
    if (minn == 98765432) minn = -1;
    cout << minn;

    return 0;
}