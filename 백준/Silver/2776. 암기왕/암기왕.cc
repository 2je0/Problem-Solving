#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int arr[1000001];
int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        cin >> m;
        for (int i = 0, temp; i < m; i++) {
            cin >> temp;
            auto p = lower_bound(arr, arr + n, temp);
            int ret = (*p == temp) && (p - arr) < n;
            cout << ret << '\n';
        }
    }

    return 0;
}
