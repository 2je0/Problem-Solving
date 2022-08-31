#include <bits/stdc++.h>
using namespace std;
int h, w, n, t;
int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> h >> w >> n;
        int a = n % h;
        int b = n / h;
        if (a == 0) {
            a = h;
            b--;
        }
        b++;
        int padding = b < 10 ? 1 : 0;
        cout << a;
        if (padding) cout << '0';
        cout << b << '\n';
    }
    return 0;
}