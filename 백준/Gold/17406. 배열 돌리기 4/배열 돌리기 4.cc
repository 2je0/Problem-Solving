#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int N, M, K = 4;
int r, c, s;
long long minn = LONG_LONG_MAX;
int arr[51][51];
int arrOrigin[51][51];
class rcs {
   public:
    int r;
    int c;
    int s;
};
rcs bundle[7];
void oneLevel(int r, int c, int s) {
    int temp = arr[r - s][c - s];
    for (int i = 0; i < 2 * s; i++) {
        arr[r - s + i][c - s] = arr[r - s + 1 + i][c - s];
    }
    for (int i = 0; i < 2 * s; i++) {
        arr[r + s][c - s + i] = arr[r + s][c - s + 1 + i];
    }
    for (int i = 0; i < 2 * s; i++) {
        arr[r + s - i][c + s] = arr[r + s - 1 - i][c + s];
    }
    for (int i = 0; i < 2 * s; i++) {
        arr[r - s][c + s - i] = arr[r - s][c + s - 1 - i];
    }
    arr[r - s][c - s + 1] = temp;
}
void rot(int r, int c, int s) {
    for (int i = 1; i <= s; i++) {
        oneLevel(r, c, i);
    }
}
void printArr() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
int arrr[6];
int cnt;
void dfs(int idx, int level) {
    if (level > K) {
        memcpy(arr, arrOrigin, sizeof(arr));
        for (int i = 0; i < K; i++) {
            int idx = arrr[i];
            rot(bundle[idx].r, bundle[idx].c, bundle[idx].s);
        }
        for (int i = 1; i <= N; i++) {
            long long sum = 0;
            for (int j = 1; j <= M; j++) {
                sum += arr[i][j];
            }
            minn = min(minn, sum);
        }
        return;
    }
    for (int i = 0; i < K; i++) {
        if (arrr[i] == 0) {
            arrr[i] = level;
            dfs(i, level + 1);
            arrr[i] = 0;
        }
    }
}
int main() {
    FIO;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            arrOrigin[i][j] = arr[i][j];
        }
    }
    for (int i = 1; i <= K; i++) {
        cin >> r >> c >> s;
        rcs temp;
        temp.r = r, temp.c = c, temp.s = s;
        bundle[i] = temp;
    }
    dfs(0, 1);

    cout << minn;

    return 0;
}