#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[101];
int cnt[101], maxx;
int main() {
    ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    cin >> n;
    for (int i = 0, f, s; i < n; i++) {
        cin >> f >> s;
        arr[i] = {f, s};
    }
    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {
        int maxVal = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j].second < arr[i].second && cnt[j] > maxVal) {
                maxVal = cnt[j];
            }
        }
        cnt[i] = maxVal + 1;
        maxx = max(cnt[i], maxx);
    }

    cout << n - maxx;
    return 0;
}
