#include <bits/stdc++.h>
#define MAX 500001
using namespace std;
typedef long long ll;
int n;
long long first[MAX], second[MAX];
vector<ll> mn, mx;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long f, s;
        cin >> f >> s;
        first[i] = f - s, second[i] = f + s;
        mn.push_back(first[i]);
        mx.push_back(second[i]);
    }
    // sort(first, first + n);
    // sort(second, second + n);
    sort(mn.begin(), mn.end());
    sort(mx.begin(), mx.end());
    for (int i = 0; i < n; i++) {
        // int a = lower_bound(second, second + n, first[i]) - second + 1;
        // int b = upper_bound(first, first + n, second[i]) - first;
        int a = lower_bound(mx.begin(), mx.end(), first[i]) - mx.begin() + 1;
        int b = upper_bound(mn.begin(), mn.end(), second[i]) - mn.begin();
        cout << a << ' ' << b << '\n';
    }
    return 0;
}