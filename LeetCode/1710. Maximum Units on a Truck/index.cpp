#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int res = 0;
        for (auto &ele : boxTypes)
        {
            if (truckSize >= ele[0])
            {
                res += ele[0] * ele[1];
                truckSize -= ele[0];
            }
            else
            {
                res += truckSize * ele[1];
                truckSize -= truckSize;
            }
            if (!truckSize)
                break;
        }
        return res;
    }
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
};