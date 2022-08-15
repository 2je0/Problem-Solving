#include <bits/stdc++.h>
#define FIO ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, sum = 0;
priority_queue<int> pq;
pair<int, int> arr[200000];
int main() {
    FIO;
    cin >> n;
    for (int i = 0, dead, ramen; i < n; i++) {
        cin >> dead >> ramen;
        arr[i] = {dead, ramen};
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        pq.push(arr[i].second * -1);
        if (arr[i].first < pq.size()) {
            pq.pop();
        }
    }
    while (pq.size()) {
        sum += pq.top() * -1;
        pq.pop();
    }
    cout << sum;
}