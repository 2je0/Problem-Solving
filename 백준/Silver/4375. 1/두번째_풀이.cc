#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int bosu(int last, int tempLast)
{
    int dp[10] = {
        0,
    };
    if (dp[tempLast])
        return dp[tempLast];
    for (int i = 0; i < 10; i++)
    {
        if (((last * i) + tempLast) % 10 == 1)
        {
            dp[tempLast] = i;
            return i;
        }
    }
}
ll sol(ll number)
{
    ll temp = number;
    int last = temp % 10;
    int cnt = 0;
    while (temp)
    {
        int tempLast = temp % 10;
        int mul = bosu(last, tempLast);
        temp = (temp + number * mul) / 10;
        cnt++;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    ll n;
    while (cin >> n)
    {
        cout << sol(n) << endl;
    }
}
