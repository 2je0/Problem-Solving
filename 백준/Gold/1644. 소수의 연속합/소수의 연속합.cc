#include <bits/stdc++.h>
#define FIO ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 4000001
using namespace std;
int n, cnt = 0, sum = 0;
vector<int> v;
bool arr[MAX];

int main() {
    FIO;
    cin >> n;
    for (int i = 2; i < MAX; i++) {
        if (arr[i]) continue;
        for (int j = i * 2; j < MAX; j += i) arr[j] = 1;
    }
    for (int i = 2; i < MAX; i++) {
        if (!arr[i]) v.push_back(i);
    }
    int left = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        while (left <= i && sum > n) {
            sum -= v[left++];
        }
        if (sum == n) cnt++;
    }
    cout << cnt;

    return 0;
}