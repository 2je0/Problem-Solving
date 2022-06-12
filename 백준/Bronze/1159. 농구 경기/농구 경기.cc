#include <bits/stdc++.h>
using namespace std;
int arr[26];
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        arr[str[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] >= 5)
        {
            cout << (char)(i + 'a');
            flag = true;
        }
    }
    if (!flag)
        cout << "PREDAJA";
    return 0;
}