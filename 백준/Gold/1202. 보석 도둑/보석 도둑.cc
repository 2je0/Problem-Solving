#include <bits/stdc++.h>
#define FIO ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, k;
long long sum = 0;
vector<pair<int, int>> bo;
vector<int> bag;
priority_queue<int> pq;
int main() {
    FIO;
    cin >> n >> k;

    for (int i = 0, m, v; i < n; i++) {
        cin >> m >> v;
        bo.push_back({m, v});
    }
    sort(bo.begin(), bo.end());
    for (int i = 0, size; i < k; i++) {
        cin >> size;
        bag.push_back(size);
    }
    sort(bag.begin(), bag.end());
    int idx = 0;
    for (int i = 0; i < k; i++) {
        while (idx < n && bo[idx].first <= bag[i]) pq.push(bo[idx++].second);
        if (pq.size()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
    return 0;
}