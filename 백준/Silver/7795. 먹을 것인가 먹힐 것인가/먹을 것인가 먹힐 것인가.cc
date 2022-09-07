#include <bits/stdc++.h>

using namespace std;
int t, n, m;
int arra[20001];
int arrb[20001];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> arra[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> arrb[i];
        }
        sort(arrb, arrb + m);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            auto idx = lower_bound(arrb, arrb + m, arra[i]);
            cnt += (idx - arrb);
        }
        cout << cnt << '\n';
    }
    return 0;
}