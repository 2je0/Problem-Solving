#include <bits/stdc++.h>
using namespace std;
string str, explore, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> str >> explore;
    for (char& c : str) {
        ret += c;
        if (ret.size() >= explore.size() && ret.substr(ret.size() - explore.size(), explore.size()) == explore) {
            ret.erase(ret.size() - explore.size(), explore.size());
        }
    }
    if (ret.size())
        cout << ret;
    else
        cout << "FRULA";

    return 0;
}