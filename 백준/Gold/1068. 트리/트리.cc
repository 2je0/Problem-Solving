#include <bits/stdc++.h>
#define MAX 104
using namespace std;
struct node {
    int p;
    vector<int> c;
};
int dfs(vector<node>& v, int n) {
    if (!v[n].c.size()) return 1;
    int res = 0;
    for (auto& ele : v[n].c) {
        res += dfs(v, ele);
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<node> v(n);
    int head;
    for (int i = 0; i < n; i++) {
        int nd;
        cin >> nd;
        if (nd == -1) head = i;
        if (nd != -1) {
            v[i].p = nd;
            v[nd].c.push_back(i);
        }
    }

    int del;
    cin >> del;
    if (del == head) {
        cout << 0;
        return 0;
    } else {
        int parent = v[del].p;
        for (int i = 0; i < v[parent].c.size(); i++) {
            if (v[parent].c[i] == del) {
                v[parent].c.erase(v[parent].c.begin() + i);
                break;
            }
        }
    }
    int res = dfs(v, head);
    cout << res;
    return 0;
}