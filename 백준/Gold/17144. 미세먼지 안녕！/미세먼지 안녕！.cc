#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int R, C, T;
int arr[50][50];
int tempArr[50][50];
pair<int, int> cleaner;
void IO() {
    FIO;
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) cleaner = {i, j};
        }
    }
}
void spread() {
    memset(tempArr, 0, sizeof(tempArr));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 0) continue;
            if (arr[i][j] == -1) {
                tempArr[i][j] = -1;
                continue;
            }
            int spreadNum = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C || arr[nx][ny] == -1) continue;
                tempArr[nx][ny] += arr[i][j] / 5;
                spreadNum++;
            }
            tempArr[i][j] += (arr[i][j] - arr[i][j] / 5 * spreadNum);
        }
    }
    memcpy(arr, tempArr, sizeof(arr));
}
void printArr() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
void cleaningDown() {
    // down
    for (int i = cleaner.first + 1; i < R - 1; i++) {
        arr[i][0] = arr[i + 1][0];
    }
    for (int i = 0; i < C - 1; i++) {
        arr[R - 1][i] = arr[R - 1][i + 1];
    }
    for (int i = R - 1; i >= cleaner.first + 1; i--) {
        arr[i][C - 1] = arr[i - 1][C - 1];
    }
    for (int i = C - 1; i > 1; i--) {
        arr[cleaner.first][i] = arr[cleaner.first][i - 1];
    }
    arr[cleaner.first][cleaner.second + 1] = 0;
}
void cleaningUp() {
    // Up
    for (int i = cleaner.first - 2; i > 0; i--) {
        arr[i][0] = arr[i - 1][0];
    }
    for (int i = 0; i < C - 1; i++) {
        arr[0][i] = arr[0][i + 1];
    }
    for (int i = 0; i < cleaner.first - 1; i++) {
        arr[i][C - 1] = arr[i + 1][C - 1];
    }
    for (int i = C - 1; i > 1; i--) {
        arr[cleaner.first - 1][i] = arr[cleaner.first - 1][i - 1];
    }
    arr[cleaner.first - 1][cleaner.second + 1] = 0;
}
void cleaning() {
    cleaningUp();
    cleaningDown();
}
int cnt() {
    int sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == -1) continue;
            sum += arr[i][j];
        }
    }
    return sum;
}
int main() {
    IO();
    while (T--) {
        spread();
        cleaning();
    }
    cout << cnt();
    return 0;
}