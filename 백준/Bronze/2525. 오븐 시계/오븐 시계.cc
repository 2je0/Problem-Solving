#include <bits/stdc++.h>
using namespace std;
int main() {
    int hour, minute, add;
    cin >> hour >> minute >> add;
    minute += add;
    cout << (hour + minute / 60) % 24 << ' ' << minute % 60;
    return 0;
}