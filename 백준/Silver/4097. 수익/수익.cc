#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
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