#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, res;
    cin >> A >> B;
    res = A * B;
    while (B) {
        cout << A * (B % 10) << '\n';
        B /= 10;
    }
    cout << res;
    return 0;
}