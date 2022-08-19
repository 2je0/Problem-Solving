#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
int arr[20][20];
int minn = INT_MAX;
void IO() {
    FIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}

int numOfPeople(int bits) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (bits & (1 << i)) sum++;
    }
    return sum;
}
int main() {
    IO();
    for (int i = 0; i < (1 << n); i++) {
        if (numOfPeople(i) != n / 2) continue;
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) continue;
            for (int k = 0; k < n; k++) {
                if ((i & (1 << k)) == 0) continue;
                sum1 += arr[j][k];
            }
        }
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) continue;
            for (int k = 0; k < n; k++) {
                if (i & (1 << k)) continue;
                sum2 += arr[j][k];
            }
        }
        minn = min(minn, abs(sum1 - sum2));
    }
    cout << minn;
    return 0;
}