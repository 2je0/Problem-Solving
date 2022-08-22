#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
int arr[10001];
void IO() {
    FIO;
    cin >> n;
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        arr[temp]++;
    }
}

int main() {
    IO();
    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i << '\n';
        }
    }
    return 0;
}