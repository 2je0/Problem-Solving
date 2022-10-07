#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int n, k;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    while (n--) {
        int a;
        cin >> a;
        pq.push(a);
    }
    int ret;
    while (k--) {
        ret = pq.top();
        pq.pop();
    }
    cout << ret;
    return 0;
}