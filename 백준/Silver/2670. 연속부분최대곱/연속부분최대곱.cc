#include <bits/stdc++.h>
using namespace std;
int n;
double minn = 1, res, mult = 1;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        double cur;
        cin >> cur;
        if (mult == 0) {
            mult = cur;
            minn = 1;
        } else
            mult *= cur;
        res = max(res, mult / minn);
        minn = min(minn, mult);
    }
    printf("%.3lf", res);

    return 0;
}