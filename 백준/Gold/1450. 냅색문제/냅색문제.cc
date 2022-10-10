#include <bits/stdc++.h>
using namespace std;
int n, c, cnt;
vector<int> v1, v2;
int arr[31];
void rec(vector<int>& v, int level, int end, int sum) {
    if (level == end) {
        v.push_back(sum);
        return;
    }
    rec(v, level + 1, end, sum);
    if (sum + arr[level] <= c) {
        rec(v, level + 1, end, sum + arr[level]);
    }
}
int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    rec(v1, 0, (n / 2), 0);
    rec(v2, (n / 2), n, 0);
    sort(v2.begin(), v2.end());
    for (auto& ele : v1) {
        cnt += upper_bound(v2.begin(), v2.end(), c - ele) - v2.begin();
    }
    cout << cnt;
    return 0;
}