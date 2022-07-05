#include <bits/stdc++.h>
#define endl '\n';

using namespace std;
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.first != b.second.first) return a.second.first > b.second.first;
    return a.second.second < b.second.second;
}
int main() {
    int n, c;
    cin >> n >> c;
    map<int, pair<int, int>> mmap;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        mmap[input].first++;
        if (mmap[input].second == 0) mmap[input].second = i + 1;
    }
    vector<pair<int, pair<int, int>>> v(mmap.begin(), mmap.end());
    sort(v.begin(), v.end(), cmp);
    for (auto& ele : v) {
        for (int i = 0; i < ele.second.first; i++) {
            cout << ele.first << ' ';
        }
    }
    return 0;
}