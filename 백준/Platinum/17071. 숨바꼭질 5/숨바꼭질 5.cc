#include <bits/stdc++.h>
#define MAX 500001
using namespace std;
int visited[2][MAX];  // visited[0][] <-- 이게 짝수
int main() {
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> q;
    q.push({1, n});  // time, pos
    visited[1][n] = 1;

    while (!q.empty()) {
        int time, x;
        tie(time, x) = q.front();
        q.pop();
        int _nx[] = {x + 1, x - 1, 2 * x};
        for (int i = 0; i < 3; i++) {
            int nx = _nx[i];
            if (nx < 0 || nx > 500000 || visited[(time + 1) & 1][nx]) continue;
            q.push({time + 1, nx});
            visited[(time + 1) & 1][nx] = time + 1;
        }
    }

    int time = 1;
    while (1) {
        int bro = k + time * (time - 1) / 2;
        if (bro >= MAX) break;
        int myTime = visited[time & 1][bro];
        if (myTime <= time) {
            cout << time - 1;
            return 0;
        }
        time++;
    }
    cout << -1;
    return 0;
}