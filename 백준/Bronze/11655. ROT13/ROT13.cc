#include <bits/stdc++.h>
using namespace std;
void transform(char &c)
{
    if (c > 'm')
    {
        c -= 13;
    }
    else if (c >= 'a' && c <= 'm')
        c += 13;
    else if (c >= 'A' && c <= 'Z')
    {
        c += 13;
        if (c > 'Z')
            c -= 26;
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            transform(str[i]);
        }
    }
    cout << str;
    return 0;
}