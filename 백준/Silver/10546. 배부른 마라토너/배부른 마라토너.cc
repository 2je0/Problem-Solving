#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map<string, int> m;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        m[s]++;  
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> s;
        m[s]--;
    }
    for (auto& ele : m) {
        if (ele.second > 0)
            cout << ele.first << '\n';
    }

    return 0;
}