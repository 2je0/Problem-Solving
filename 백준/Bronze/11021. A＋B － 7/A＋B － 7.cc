#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        printf("Case #%d: %d\n", i, a + b);
    }
    return 0;
}