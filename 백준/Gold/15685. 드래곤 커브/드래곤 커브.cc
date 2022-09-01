#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, cnt;
int arr[104][104];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
vector<int> v;
void fillCurve() {
    v.push_back(0);
    for (int i = 0; i < 10; i++) {
        int s = v.size();
        for (int j = s - 1; j >= 0; j--) {
            int temp = v[j] + 1 > 3 ? 0 : v[j] + 1;
            v.push_back(temp);
        }
    }
}
int main() {
    FIO;
    fillCurve();
    cin >> n;
    while (n--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        arr[x][y] = 1;
        for (int i = 0; i < pow(2, g); i++) {
            int dir = v[i] + d > 3 ? v[i] + d - 4 : v[i] + d;
            x = x + dx[dir];
            y = y + dy[dir];
            arr[x][y] = 1;
        }
    }
    for (int y = 0; y < 101; y++) {
        for (int x = 0; x < 101; x++) {
            if (arr[x][y] && arr[x + 1][y] && arr[x][y + 1] && arr[x + 1][y + 1]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}