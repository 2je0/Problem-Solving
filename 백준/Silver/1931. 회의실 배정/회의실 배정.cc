#include <bits/stdc++.h>
#define FIO ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, endtime = 0, cnt = 0;
pair<int, int> arr[100004];
int main() {
    FIO;
    cin >> n;
    for (int i = 0, start, end; i < n; i++) {
        cin >> start >> end;
        arr[i] = {end, start};
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        if (endtime <= arr[i].second) {
            endtime = arr[i].first;
            cnt++;
        }
    }
    cout << cnt;
}