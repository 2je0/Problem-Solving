#include <bits/stdc++.h>
#define MAXN 123456
using namespace std;
typedef long long ll;
int t[MAXN], a[MAXN], h[MAXN];
ll n, hatk;
ll low, high = LONG_LONG_MAX, res;
bool check(ll hmax, ll hatk) {
    ll hcur = hmax;

    for (int i = 0; i < n; i++) {
        if (t[i] == 2) {
            hcur = hcur + h[i] > hmax ? hmax : hcur + h[i];
            hatk += a[i];
        } else if (t[i] == 1) {
            ll r = h[i] % hatk ? h[i] / hatk : h[i] / hatk - 1;
            hcur -= (a[i] * r);
        }
        if (hcur <= 0) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> hatk;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i] >> h[i];
    }
    while (low <= high) {
        ll mid = (high + low) / 2;
        if (check(mid, hatk)) {
            high = mid - 1;
            res = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << res;
    return 0;
}