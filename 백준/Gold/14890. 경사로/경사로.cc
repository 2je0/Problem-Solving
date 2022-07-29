#include <bits/stdc++.h>
#define MAX 104
using namespace std;
int arr[MAX][MAX];
int arrT[MAX][MAX];
int N, L;

int findPath(int arr[MAX][MAX]) {
    int path = 0;
    for (int i = 0; i < N; i++) {
        int waiting = 1;
        bool flag = true;
        for (int j = 1; j < N; j++) {
            if (arr[i][j] == arr[i][j - 1] + 1) {
                if (waiting >= L) {
                    waiting = 1;
                } else {
                    flag = false;
                    break;
                }
            } else if (arr[i][j] == arr[i][j - 1] - 1) {
                if (waiting >= 0) {
                    waiting = -L + 1;
                } else {
                    flag = false;
                    break;
                }
            } else if (arr[i][j] == arr[i][j - 1]) {
                waiting++;
            } else {
                flag = false;
                break;
            }
        }
        if (waiting < 0 || !flag) continue;
        path++;
    }
    return path;
}
int main() {
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            arrT[j][i] = arr[i][j];
        }
    }

    cout << findPath(arr) + findPath(arrT);
    return 0;
}