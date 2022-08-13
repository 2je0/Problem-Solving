#include <bits/stdc++.h>
#define FIO ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;

int main() {
    FIO;
    while (1) {
        long long maxx = LONG_LONG_MIN, minn = 0;
        long long curSum = 0;
        cin >> n;
        if (n == 0) break;
        for (int i = 0, cur; i < n; i++) {
            cin >> cur;
            curSum += cur;
            maxx = max(maxx, curSum - minn);
            minn = min(curSum, minn);
        }
        cout << maxx << '\n';
    }

    return 0;
}