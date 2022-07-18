#include <bits/stdc++.h>
using namespace std;
int mx = INT_MIN;

int calc(int first, char exp, int second) {
    if (exp == '+')
        return first + second;
    else if (exp == '-')
        return first - second;
    else if (exp == '*')
        return first * second;
    else if (exp == '/')
        return first / second;
}

void DFS(string str, int res) {
    int len = str.length();
    if (!len) {
        mx = max(res, mx);
        return;
    }
    int front = calc(res, str[0], str[1] - '0');
    DFS(str.substr(2), front);

    if (len > 3) {
        int back = calc(str[1] - '0', str[2], str[3] - '0');
        int total = calc(res, str[0], back);
        DFS(str.substr(4), total);
    }
}
int main() {
    int n;
    cin >> n;
    string input;
    cin >> input;
    DFS(input.substr(1), input[0] - '0');
    cout << mx;

    return 0;
}