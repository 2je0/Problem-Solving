#include <bits/stdc++.h>

using namespace std;
int n, m, low = 10000, high, mid;
int arr[100001];
bool check(int len) {
    int video = 0;
    int sum = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > len) return false;
        video += arr[i];
        if (video > len) {
            video = arr[i];
            sum++;
        }
    }
    if (sum > m)
        return false;
    else
        return true;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        high += arr[i];
        low = min(low, arr[i]);
    }
    while (low < high) {
        mid = (low + high) / 2;
        if (check(mid))
            high = mid;
        else
            low = mid + 1;
    }
    cout << low;

    return 0;
}