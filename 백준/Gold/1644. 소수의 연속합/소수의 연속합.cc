#include <bits/stdc++.h>
#define FIO ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, cnt = 0, sum = 0;
deque<int> dq;
bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    FIO;
    cin >> n;

    int left = 0;
    for (int i = 2; i <= n; i++) {
        if (!isPrime(i)) continue;
        dq.push_back(i);
        sum += i;
        while (dq.size() && sum > n) {
            sum -= dq.front();
            dq.pop_front();
        }
        if (sum == n) cnt++;
    }
    cout << cnt;

    return 0;
}