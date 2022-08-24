#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int sum;
void IO() {
    FIO;
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%1d", &num);
        sum += num;
    }
}

int main() {
    IO();
    cout << sum;
    return 0;
}