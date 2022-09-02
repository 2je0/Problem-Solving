#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int n, len;
int main() {
    cin >> n;
    for (int i = 0, num; i < n; i++) {
        cin >> num;
        auto idx = lower_bound(arr, arr + len, num);
        if (*idx == 0) {
            
            len++;
        }
        *idx = num;
    }
    cout << len;

    return 0;
}