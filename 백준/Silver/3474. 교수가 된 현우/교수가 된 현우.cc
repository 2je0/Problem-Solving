#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int input;
        scanf("%d", &input);
        int res = 0;
        while (input) {
            res += (input / 5);
            input /= 5;
        }
        printf("%d\n", res);
    }

    return 0;
}