#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int dp[1001];
int trace[1001];
int n, len, lastIdx, lastValue = -1;
vector<int> v;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int maxValue = 0;
        int maxIdx = -1;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] > maxValue) {
                maxValue = dp[j];
                maxIdx = j;
            }
        }
        dp[i] = maxValue + 1;
        trace[i] = maxIdx;
        if (dp[i] > lastValue) {
            lastValue = dp[i];
            lastIdx = i;
        }
    }
    for (int i = lastIdx; i != -1; i = trace[i]) {
        v.push_back(arr[i]);
    }
    cout << lastValue << '\n';
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }

    return 0;
}