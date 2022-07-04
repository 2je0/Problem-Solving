#include <bits/stdc++.h>
using namespace std;
int arr[64][64];
bool isAllSame(int i, int j, int size) {
    int f = arr[i][j];
    for (int x = i; x < i + size; x++) {
        for (int y = j; y < j + size; y++) {
            if (arr[x][y] != f) return false;
        }
    }
    return true;
}
void recur(int i, int j, int size) {
    if (isAllSame(i, j, size)) {
        printf("%d", arr[i][j]);
    } else {
        printf("(");
        int dd[] = {0, size / 2};
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                recur(i + dd[x], j + dd[y], size / 2);
            }
        }
        printf(")");
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    recur(0, 0, n);
    return 0;
}