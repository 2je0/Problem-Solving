#include <bits/stdc++.h>
#define MAX 100004
using namespace std;

int visited[MAX];
int before[MAX];
queue<int> q;
int res;
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;

    q.push(n);
    visited[n] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == k) {
            res = visited[x];
            break;
        }
        int _nx[3] = {x - 1, x + 1, 2 * x};
        for (int i = 0; i < 3; i++) {
            int nx = _nx[i];
            if (nx < 0 || nx > 100000 || visited[nx]) continue;
            q.push(nx);
            visited[nx] = visited[x] + 1;
            before[nx] = x;
        }
    }
    for (int i = k; i != n; i = before[i]) {
        v.push_back(i);
    }
    v.push_back(n);
    cout << res - 1 << '\n';
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }
    return 0;
}
