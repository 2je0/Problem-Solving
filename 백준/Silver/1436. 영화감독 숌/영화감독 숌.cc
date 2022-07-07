#include <bits/stdc++.h>
using namespace std;

int main() {
    int num = 0;
    int n ;cin>> n;
    long long res = 0;
    while (1) {
        num++;
        string str = to_string(num);

        if (str.find("666") != string::npos) n--;
        if (!n) {
            res = num;
            break;
        }
    }
    cout << res;
    return 0;
}