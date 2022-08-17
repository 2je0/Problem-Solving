#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, x, start = 0, cnt = 0;
long long sum = 0;
int arr[100001];
int main() {
    FIO;
    cin >> n;
    int end = n - 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    sort(arr, arr + n);
    while (start < end) {
        if (arr[start] + arr[end] < x) {
            start++;
        } else if (arr[start] + arr[end] > x) {
            end--;
        } else {
            cnt++, start++, end--;
        }
    }
    cout << cnt;
    return 0;
}