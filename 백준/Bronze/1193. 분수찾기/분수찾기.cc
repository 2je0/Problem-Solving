#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int x, n;
void IO() {
    FIO;
    cin >> x;
    n = sqrt(x * 2);
}

int main() {
    IO();
    while (1) {
        if (n * (n - 1) / 2 < x && x <= n * (n + 1) / 2) break;
        n++;
    }
    int before = n * (n - 1) / 2;
    int total = n + 1;
    int mo = x - before;
    int ja = total - mo;
    if (n & 1)
        cout << ja << '/' << mo;
    else
        cout << mo << '/' << ja;
    return 0;
}