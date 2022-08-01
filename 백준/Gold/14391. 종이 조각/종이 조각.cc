#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[4][4];
int maxx = -1;
int calcSum(int s, int value) {
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    for (int s = 0; s < (1 << n * m); s++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                int idx = i * m + j;
                if (s & (1 << idx)) {
                    sum += cur;
                    cur = 0;
                } else {
                    cur = cur * 10 + arr[i][j];
                }
            }
            sum += cur;
        }
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                int idx = i * m + j;
                if ((s & (1 << idx)) == 0) {
                    sum += cur;
                    cur = 0;
                } else {
                    cur = cur * 10 + arr[i][j];
                }
            }
            sum += cur;
        }
        maxx = max(maxx, sum);
    }
    cout << maxx;
    return 0;
}