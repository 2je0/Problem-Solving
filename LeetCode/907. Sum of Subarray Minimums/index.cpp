#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        static const int MOD = 1e9 + 7;
        stack<int> st;
        int j, k;
        int n = arr.size();
        long long res = 0;
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && arr[st.top()] > (i == n ? -1 : arr[i]))
            {
                int j = st.top();
                st.pop();
                int k = st.empty() ? -1 : st.top();
                long long first = arr[j] * (i - j) % MOD;
                long long second = first * (j - k) % MOD;
                res += second;
                res %= MOD;
            }
            st.push(i);
        }
        return res;
    }
};