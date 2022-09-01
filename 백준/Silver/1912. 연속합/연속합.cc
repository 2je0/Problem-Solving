#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, lmin = 0, sum, gmax = INT_MIN;
int main() {
    FIO;
    cin >> n;
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        sum += temp;
        gmax = max(gmax, sum - lmin);
        lmin = min(lmin, sum);
    }
    cout << gmax;
    return 0;
}