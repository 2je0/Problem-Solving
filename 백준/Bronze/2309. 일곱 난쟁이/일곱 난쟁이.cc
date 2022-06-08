#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    int arr[9];
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    sort(arr, arr + 9);
    int target = sum - 100;
    pair<int, int> deleteIdx;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                deleteIdx = {i, j};
                break;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (i == deleteIdx.first || i == deleteIdx.second)
            continue;

        printf("%d\n", arr[i]);
    }

    return 0;
}