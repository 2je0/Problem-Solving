#include <bits/stdc++.h>
using namespace std;
bool cmp(string& a, string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}
int main() {
    int n;
    vector<string> res;
    cin >> n;
    while (n--) {
        string input;
        cin >> input;
        int flag = -1;
        for (int i = 0; i < input.size(); i++) {
            if (isdigit(input[i])) {  // 숫자면
                if (flag == -1)       // flag가 없다면
                    flag = i;

            } else {  // 문자면
                if (flag != -1) {
                    string temp = input.substr(flag, i - flag);
                    res.push_back(temp);
                    flag = -1;
                }
            }
        }
        if (flag != -1) {
            string temp = input.substr(flag, input.size() - flag);
            res.push_back(temp);
        }
    }
    for (auto& ele : res) {
        while (ele[0] == '0') ele.erase(0, 1);
        if (!ele.size()) ele = '0';
    }
    sort(res.begin(), res.end(), cmp);
    for (auto& ele : res) cout << ele << '\n';
    return 0;
}