#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int total;
    cin >> total;
    int n, sum = 0;
    cin >> n;

    while (n--) {
        int price, num;
        cin >> price >> num;
        sum += (price * num);
    }
    if (sum == total) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}