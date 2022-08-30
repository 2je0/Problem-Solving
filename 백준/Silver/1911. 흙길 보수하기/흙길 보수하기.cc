#include <bits/stdc++.h>
using namespace std;
int n, l, idx = -1, res;
pair<int, int> arr[10004];

int main() {
    cin >> n >> l;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        int low = arr[i].first;
        int high = arr[i].second;
        if (high <= idx + 1) continue;
        if (low <= idx) {
            low = idx + 1;
        }
        int len = high - low;
        int wood = len / l;
        idx = high - 1;
        if (len % l) {
            wood++;
            idx = low + (wood * l) - 1;
        }
        res += wood;
    }
    cout << res;
    return 0;
}