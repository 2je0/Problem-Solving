#include <bits/stdc++.h>
using namespace std;
int n, lft = 0, right = 0;
long long sum = 0;
int arr[100001];
bool check[100001];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int right = 0; right < n; right++) {
        while (check[arr[right]]) {
            check[arr[lft++]] = 0;
        }
        check[arr[right]] = 1;
        sum += (right - lft + 1);
    }
    cout << sum;
    return 0;
}