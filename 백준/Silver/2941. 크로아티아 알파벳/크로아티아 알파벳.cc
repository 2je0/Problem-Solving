#include <bits/stdc++.h>
using namespace std;
string str;
int idx, cnt;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> str;
    while (1) {
        char a = str[idx];
        if (a == '\0') break;
        if (a == 'c') {
            if (str[idx + 1] == '-' || str[idx + 1] == '=') {
                cnt++, idx += 2;
            } else {
                cnt++, idx++;
            }
        } else if (a == 'd') {
            if (str[idx + 1] == 'z' && str[idx + 2] == '=') {
                cnt++, idx += 3;
            } else if (str[idx + 1] == '-')
                cnt++, idx += 2;
            else {
                cnt++, idx++;
            }
        } else if (a == 'l' && str[idx + 1] == 'j') {
            cnt++, idx += 2;
        } else if (a == 'n' && str[idx + 1] == 'j') {
            cnt++, idx += 2;
        } else if (a == 's' && str[idx + 1] == '=') {
            cnt++, idx += 2;
        } else if (a == 'z' && str[idx + 1] == '=') {
            cnt++, idx += 2;
        } else {
            cnt++, idx++;
        }
    }
    cout << cnt;
    return 0;
}