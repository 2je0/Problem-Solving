#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
struct node {
    vector<int> path;
    int level;
};

int visited[100004];
int minLevel = INT_MAX;
int cnt = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    if (n > k) {
        cout << n - k << '\n';
        for (int i = n; i >= k; i--) {
            cout << i << ' ';
        }
        return 0;
    }
    queue<node> q;
    node nd;
    nd.path.push_back(n);
    nd.level = 0;
    q.push(nd);
    visited[n] = 1;
    while (!q.empty()) {
        vector<int> path = q.front().path;
        int level = q.front().level;
        q.pop();
        int x = path.back();
        // cout << x << " " << level << endl;
        if (x == k) {
            cout << level << '\n';
            for (auto& ele : path) {
                cout << ele << ' ';
            }
            return 0;
        }

        int nx[3] = {x - 1, x + 1, 2 * x};
        for (int i = 0; i < 3; i++) {
            if (nx[i] < 0 || nx[i] > 100000 || visited[nx[i]]) continue;
            node nnd;
            nnd.path = path;
            nnd.path.push_back(nx[i]);
            nnd.level = level + 1;
            visited[nx[i]] = 1;
            q.push(nnd);
        }
    }
    return 0;
}