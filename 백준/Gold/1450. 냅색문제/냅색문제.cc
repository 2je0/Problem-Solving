#include <bits/stdc++.h>
using namespace std;
long long n, c, cnt;
vector<long long> v1, v2;
int arr[31];
void rec(vector<long long>& v, int level, int end, long long sum) {
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
        long long b = c - ele;
        long long k = upper_bound(v2.begin(), v2.end(), b) - v2.begin();
        cnt += k;
    }
    cout << cnt;

    return 0;
}