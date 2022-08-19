#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, k, numOfPlugin, cnt;
int arr[101];
queue<int> v[101];
bool plugIn[101];
void IO() {
    FIO;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        v[arr[i]].push(i);
    }
}

int main() {
    IO();
    for (int i = 0; i < k; i++) {
        int p = arr[i];
        if (plugIn[p]) {
            v[p].pop();
            continue;
        }                       
        if (numOfPlugin < n) {
            numOfPlugin++;
            v[p].pop();
            plugIn[p] = 1;
        } else {
            int lastPlug, lastIdx = -1;
            for (int j = 0; j < k; j++) {
                if (plugIn[j] == 0) continue;
                if (v[j].empty()) {
                    lastPlug = j;
                    break;
                }
                if (lastIdx < v[j].front()) {
                    lastPlug = j;
                    lastIdx = v[j].front();
                }
            }
            plugIn[lastPlug] = 0;
            plugIn[p] = 1;
            v[p].pop();
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}