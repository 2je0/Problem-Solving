#include <bits/stdc++.h>
#define FIO ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, c, r;

int dfs(int n, int r, int c) {
    if (n == 0) return 1;
    int size = 1 << (n - 1);
    int newR = r, newC = c, res = 0;
    if (r >= size) {
        res += size * size * 2;
        newR -= size;
    }
    if (c >= size) {
        res += size * size;
        newC -= size;
    }
    return res + dfs(n - 1, newR, newC);
}
int main() {
    FIO;
    cin >> n >> r >> c;
    cout << dfs(n, r, c) - 1;

    return 0;
}