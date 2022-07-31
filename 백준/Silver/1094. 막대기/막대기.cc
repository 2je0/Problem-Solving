#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, cnt = 0;
    cin >> x;
    for (int i = 0; i < 7; i++) {
        if (x & (1 << i)) cnt++;
    }
    cout << cnt;
    return 0;
}