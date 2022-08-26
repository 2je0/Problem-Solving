#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int t, r;
void IO() {
    FIO;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string a;
        cin >> r;
        cin >> a;
        for (int j = 0; j < a.length(); j++) {
            for (int k = 0; k < r; k++) {
                cout << a[j];
            }
        }
        cout << '\n';
    }
}

int main() {
    IO();
    return 0;
}