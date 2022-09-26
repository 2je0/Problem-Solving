#include <bits/stdc++.h>
using namespace std;
int arr[300001], n, m, low = 1, high, ret;
bool check(int mid) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += arr[i] / mid;
        if (arr[i] % mid) cnt++;
    }
    return cnt <= n;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        high = max(high, arr[i]);
    }
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            high = mid - 1;
            ret = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << ret;
    return 0;
}