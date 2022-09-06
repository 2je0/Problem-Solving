#include <bits/stdc++.h>

using namespace std;
int n, m;
long long low = 0, high, mid;
int arr[100001];
int check(int len) {
    long long cur = 0;
    int sum = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > len) return 1000000;
        cur += arr[i];
        if (cur > len) {
            cur = arr[i];
            sum++;
        }
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        high += arr[i];
    }
    while (low < high) {
        mid = ((low + high) / 2);
        int temp = check(mid);
        if (temp <= m)
            high = mid;
        else
            low = mid + 1;
    }
    cout << low;

    return 0;
}