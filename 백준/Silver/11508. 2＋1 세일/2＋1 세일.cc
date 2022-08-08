#include <bits/stdc++.h>
using namespace std;
int n;
long long sum;
int arr[100004];
int main() {
    cin >> n;
    for (int i = 0, c; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++) {
        if (i % 3 == 2) continue;
        sum += arr[i];
    }
    cout << sum;

    return 0;
}