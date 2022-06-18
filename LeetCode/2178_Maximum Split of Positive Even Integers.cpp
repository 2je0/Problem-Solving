#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        vector<long long> result;
        if (!(finalSum & 1))
        {
            long long half = finalSum / 2;
            for (int i = 1; i <= half; i++)
            {
                if (half - i > i)
                {
                    result.push_back(i * 2);
                    half -= i;
                }
                else
                {
                    result.push_back(half * 2);
                    break;
                }
            }
        }
        return result;
    }
};