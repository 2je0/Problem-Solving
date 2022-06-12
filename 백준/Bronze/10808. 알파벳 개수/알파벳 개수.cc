#include <bits/stdc++.h>
using namespace std;
int arr[26];
int main()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        printf("%d ", arr[i]);
    return 0;
}