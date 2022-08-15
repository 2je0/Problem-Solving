#include <bits/stdc++.h>
#define FIO ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, endtime = 0;
pair<int, int> arr[1000000];
int main() {
    FIO;
    cin >> n;
    for (int i = 0, arrive, time; i < n; i++) {
        cin >> arrive >> time;
        arr[i] = {arrive, time};
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        if (endtime < arr[i].first) {  // 소가 올때까지 기다려야 하는 경우
            endtime = arr[i].first + arr[i].second;
        } else {
            endtime += arr[i].second;
        }
    }
    cout << endtime;
}