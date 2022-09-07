#include <bits/stdc++.h>

using namespace std;
int n, m, cnt;
int a[200001];
map<int, int> ab;
map<int, int> ba;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        ab[temp]++;
        ba[temp]--;
    }
    for (int i = 0, temp; i < m; i++) {
        cin >> temp;
        ba[temp]++;
        ab[temp]--;
    }
    for (auto& ele : ab) {
        if (ele.second == 1) cnt++;
    }
    for (auto& ele : ba) {
        if (ele.second == 1) cnt++;
    }
    cout << cnt;
    return 0;
}