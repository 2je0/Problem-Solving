#include <bits/stdc++.h>
using namespace std;
int cost[4];
int park[100];
int sum = 0;
int main()
{
    // freopen("input.txt", "r", stdin);
    for (int i = 1; i < 4; i++)
        scanf("%d", &cost[i]);
    for (int i = 0; i < 3; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        for (int j = s; j < e; j++)
            park[j]++;
    }
    for (int i = 0; i < 100; i++)
        sum += (park[i] * cost[park[i]]);
    printf("%d", sum);
    return 0;
}