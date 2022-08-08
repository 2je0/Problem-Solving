#include <bits/stdc++.h>
using namespace std;
long long n, t, sum;
priority_queue<int> pq;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        pq.push(t);
    }
    for (int i = 0; i < n; i++) {
        if (pq.top() - i > 0) {
            sum += (pq.top() - i);
            pq.pop();
        } else
            break;
    }
    cout << sum;
    return 0;
}