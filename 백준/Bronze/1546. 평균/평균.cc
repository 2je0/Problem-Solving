#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[1000];
int sum, n, maxx;
void IO() {
    FIO;
    cin >> n;
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        maxx = max(maxx, temp);
        sum += temp;
    }
}

int main() {
    IO();
    cout << sum * 100.0 / (maxx * n);
    return 0;
}