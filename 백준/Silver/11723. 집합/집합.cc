#include <bits/stdc++.h>
using namespace std;
int n, s, num;
char input[10];
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", input);
        if (!strcmp(input, "add")) {
            scanf("%d", &num);
            s |= (1 << num);
        } else if (!strcmp(input, "remove")) {
            scanf("%d", &num);
            s &= ~(1 << num);
        } else if (!strcmp(input, "check")) {
            scanf("%d", &num);
            if (s & (1 << num))
                printf("1\n");
            else
                printf("0\n");
        } else if (!strcmp(input, "toggle")) {
            scanf("%d", &num);
            if (s & (1 << num))
                s -= 1 << num;
            else
                s += 1 << num;
        } else if (!strcmp(input, "all")) {
            s = (1 << 22) - 1;
        } else if (!strcmp(input, "empty")) {
            s = 0;
        }
    }
    return 0;
}