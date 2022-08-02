#include <bits/stdc++.h>
using namespace std;
string removepikachu(string str, string delimeter) {
    long long pos = 0;
    while ((pos = str.find(delimeter)) != string::npos) {
        str.erase(pos, delimeter.length());
        str.insert(pos, "#");
    }
    return str;
}
int main() {
    string str;
    cin >> str;
    string output = removepikachu(str, "pi");
    output = removepikachu(output, "ka");
    output = removepikachu(output, "chu");
    for (char& c : output) {
        if (c != '#') {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}