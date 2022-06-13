#include <bits/stdc++.h>
#define MAX 100004
using namespace std;
string arr[MAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    map<string, int> strkey;
    // map<int, string> intkey;

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string input;
        cin >> input;
        strkey[input] = i;
        arr[i] = input;
    }

    for (int i = 0; i < m; i++)
    {
        string input;
        cin >> input;
        int isdigit = atoi(input.c_str());
        if (isdigit)
            cout << arr[isdigit] << '\n';
        else
            cout << strkey[input] << '\n';
    }
    return 0;
}