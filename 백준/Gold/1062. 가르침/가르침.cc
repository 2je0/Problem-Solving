#include <bits/stdc++.h>
using namespace std;
int N, K;
int arr[50];
int maxx = 0;

int numOfReadable(int answer) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if ((answer | arr[i]) == answer) cnt++;
    }
    return cnt;
}
void dfs(int now, int depth, int answer) {
    if (depth >= K) {
        int num = numOfReadable(answer);
        maxx = max(num, maxx);
        return;
    }
    for (int i = now + 1; i < 26; i++) {
        dfs(i, depth + 1, answer | (1 << i));
    }
}
int main() {
    cin >> N >> K;
    if (K < 5) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (char& c : str) {
            arr[i] |= (1 << (c - 'a'));
        }
    }

    dfs(-1, 0, 0);
    cout << maxx;
    return 0;
}