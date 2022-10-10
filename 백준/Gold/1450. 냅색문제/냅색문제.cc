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
void test() {
    cout << "arr : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    cout << "v1 : ";
    for (auto& ele : v1) {
        cout << ele << ' ';
    }
    cout << '\n';
    cout << "v2 : ";
    for (auto& ele : v2) {
        cout << ele << ' ';
    }
    cout << "\ncnt : ";
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
        int b = c - ele;
        int k = upper_bound(v2.begin(), v2.end(), b) - v2.begin();
        cnt += k;
    }
    // test();
    cout << cnt;

    return 0;
}