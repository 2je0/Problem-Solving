#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int arr[15004];
int cnt = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int start = 0, end = n - 1;
    while (start < end)
    {
        int sum = arr[start] + arr[end];
        if (sum == m)
        {
            cnt++;
            start++;
            end--;
        }
        else if (sum > m)
        {
            end--;
        }
        else
            start++;
    }
    cout << cnt;
    return 0;
}