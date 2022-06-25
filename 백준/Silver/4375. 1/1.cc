#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
ll sol(ll n)
{
    ll cnt = 1;
    ll num = 1;
    while (1)
    {
        if (!(num % n))
        {
            break;
        }
        num = num * 10 + 1;
        num %= n;
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