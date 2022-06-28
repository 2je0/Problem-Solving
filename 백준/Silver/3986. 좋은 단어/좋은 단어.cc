#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int isGood(string input)
{
    stack<char> s;
    s.push(input[0]);
    for (int i = 1; i < input.length(); i++)
    {
        if (!s.empty() && s.top() == input[i])
        {
            s.pop();
        }
        else
            s.push(input[i]);
    }
    if (s.empty())
        return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        cnt += isGood(input);
    }
    cout << cnt;
}