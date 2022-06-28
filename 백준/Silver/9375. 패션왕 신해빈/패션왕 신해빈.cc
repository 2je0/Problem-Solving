#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        map<string, int> mmap;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            string name, type;
            cin >> name >> type;
            mmap[type]++;
        }
        long long res = 1;
        for (auto &ele : mmap)
        {
            res = res * (ele.second + 1);
        }
        cout << res - 1 << endl;
    }
    return 0;
}