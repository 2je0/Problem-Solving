#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        priority_queue<int> pq;
        for (auto &ele : timePoints)
        {
            pq.push(formatToMin(ele));
        }
        int maxele = pq.top();
        int ftemp = maxele;
        int stemp = -1;
        int result = 2000;
        for (int i = 0; i < timePoints.size() - 1; i++)
        {
            pq.pop();
            stemp = pq.top();
            if (ftemp - stemp < result)
                result = ftemp - stemp;
            ftemp = stemp;
        }
        if (maxele - ftemp > 12 * 60)
        {
            int lastsub = 24 * 60 - (maxele - ftemp);
            if (lastsub < result)
                result = lastsub;
        }
        return result;
    }
    int formatToMin(string input)
    {
        string t = input.substr(0, 2);
        string m = input.substr(3, 5);
        int totalMin = atoi(t.c_str()) * 60 + atoi(m.c_str());
        return totalMin;
    }
};