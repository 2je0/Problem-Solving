#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimeter)
{
    vector<string> ret;
    long long pos;
    string token = "";

    while ((pos = input.find(delimeter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    ret.push_back(input);
    return ret;
}

int main()
{
    string a = "ū���̴� �ٺ����� �����̿���";
    vector<string> ret = split(a, " ");
    for (string ele : ret)
    {
        cout << ele << '\n';
    }
}