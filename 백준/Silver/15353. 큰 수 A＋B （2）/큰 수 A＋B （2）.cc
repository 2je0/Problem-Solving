#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.length() < b.length()) {
        string temp = a;
        a = b;
        b = temp;
    }
    int olym = 0;
    string res;
    for (int i = 0; i < a.length(); i++) {
        char cha = a[i];
        char chb = b.length() <= i ? '0' : b[i];
        int plus = cha - '0' + chb - '0' + olym;
        if (plus > 9) {
            olym = 1;
            res += to_string(plus - 10);
        } else {
            olym = 0;
            res += to_string(plus);
        }
    }
    if (olym) res += '1';
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}