#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int arr[9];
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + 9);
    do
    {
        int sum = accumulate(arr, arr + 7, 0);
        if (sum == 100)
            break;
    } while (next_permutation(arr, arr + 9));
    for (int i = 0; i < 7; i++)
        printf("%d\n", arr[i]);

    return 0;
}