#include <bits/stdc++.h>
using namespace std;
int n;
long long sum;
int arr[1004];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        sum += arr[i] * (n - i);
    }
    cout << sum;
    return 0;
}