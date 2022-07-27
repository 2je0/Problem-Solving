#include <bits/stdc++.h>
using namespace std;
int N;
int minIng[4];
int arr[15][5];
int visited[15];
int minPrice = 500 * 16;
int bit;

void dfs(int now, int p, int f, int s, int v, int price) {
    if (now >= N) return;
    if (p >= minIng[0] && f >= minIng[1] && s >= minIng[2] && v >= minIng[3]) {
        if (price <= minPrice) {
            minPrice = price;
            int temp = 0;
            for (int i = 14; i >= 0; i--) {
                temp += visited[i] ? 1 : 0;
                temp = temp << 1;
            }
            bit = temp;
        }
        return;
    }
    int i = now + 1;
    dfs(i, p, f, s, v, price);
    visited[i] = 1;
    dfs(i, p + arr[i][0], f + arr[i][1], s + arr[i][2], v + arr[i][3], price + arr[i][4]);
    visited[i] = 0;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &minIng[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    dfs(-1, 0, 0, 0, 0, 0);
    printf("%d\n", minPrice == 500 * 16 ? -1 : minPrice);

    for (int i = 0; i < 16; i++) {
        if (bit & 1) printf("%d ", i);
        bit >>= 1;
    }

    return 0;
}