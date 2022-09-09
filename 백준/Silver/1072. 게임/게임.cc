#include <bits/stdc++.h>
using namespace std;
long long x, y, z, e;
long long high = 1e9, low, res;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> x >> y;
    z = y * 100/ x ;
    while (low <= high) {
        long long mid = (high + low) / 2;

        if ((y + mid) * 100/ (x + mid)  > z) {
            high = mid - 1;
            res = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << (res ? res : -1);

    return 0;
}