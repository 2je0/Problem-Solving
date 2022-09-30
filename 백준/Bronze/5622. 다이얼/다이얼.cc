#include <bits/stdc++.h>
using namespace std;

int main() {
    char a;
    int cnt = 0;
    while (cin >> a) {
        int b = a - 'A';
        if (b >= 18) b--;
        if (a == 'Z') b--;
        cnt += b / 3 + 3;
    }
    cout << cnt;
    return 0;
}