#include <bits/stdc++.h>
using namespace std;
vector<string> split(string input, string delimeter)
{
    vector<string> ret;
    long long pos = 0;
    while ((pos = input.find(delimeter)) != string::npos)
    {

        string token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    ret.push_back(input);
    return ret;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    string input;
    cin >> n >> input;
    string deli = "*";
    vector<string> sp = split(input, deli);
    reverse(sp[1].begin(), sp[1].end());

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        int firstFind = temp.find(sp[0]);
        reverse(temp.begin(), temp.end());
        int secondFind = temp.find(sp[1]);
        bool size = (temp.length() >= input.length() - 1);
        if (!firstFind && !secondFind && size)
        {
            cout << "DA\n";
        }
        else
            cout << "NE\n";
    }
    return 0;
}