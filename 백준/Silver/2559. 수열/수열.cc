#include <bits/stdc++.h>
using namespace std;
int arr[100004];
int main()
{
    // freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sum = accumulate(arr, arr + k, 0);
    int max = sum;
    for (int i = k; i < n; i++)
    {
        sum = sum + arr[i] - arr[i - k];
        if (sum > max)
            max = sum;
    }
    cout << max;
    return 0;
}