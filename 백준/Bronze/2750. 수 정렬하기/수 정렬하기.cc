#include <bits/stdc++.h>
using namespace std;
int n, arr[1001];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}