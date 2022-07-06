#include <bits/stdc++.h>

using namespace std;
int arr[104][104];
int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char input;
            cin >> input;
            if (input == 'c')
                arr[i][j] = 0;
            else {
                if (j == 0)
                    arr[i][j] = -1;
                else {
                    if (arr[i][j - 1] > -1)
                        arr[i][j] = arr[i][j - 1] + 1;
                    else
                        arr[i][j] = -1;
                }
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}