#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int start = 1, end = m;
    int res = 0;
    for (int i = 0; i < k; i++) {
        int apple;
        cin >> apple;
        if (start <= apple && apple <= end)
            continue;
        else if (apple < start) {
            int temp = start - apple;
            res += temp;
            start -= temp;
            end -= temp;
        } else {
            int temp = apple - end;
            res += temp;
            start += temp;
            end += temp;
        }
    }
    cout << res;
    return 0;
}