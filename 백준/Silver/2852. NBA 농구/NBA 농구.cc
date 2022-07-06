#include <bits/stdc++.h>

using namespace std;
int score[3];
int wintime[3];
int toSecond(string input) {
    string h = input.substr(0, 2);
    string s = input.substr(3, 2);
    return atoi(h.c_str()) * 60 + atoi(s.c_str());
}
int main() {
    int n;
    cin >> n;
    int winner = 0;
    int time = 0;
    while (n--) {
        int team = 0;
        string t;
        cin >> team >> t;
        int inputTime = toSecond(t);
        if (winner) {
            wintime[winner] += inputTime - time;
        }
        score[team]++;
        if (score[1] > score[2])
            winner = 1;
        else if (score[1] < score[2])
            winner = 2;
        else
            winner = 0;
        time = inputTime;
    }
    if (winner) {
        wintime[winner] += 48 * 60 - time;
    }
    printf("%02d:%02d\n", wintime[1] / 60, wintime[1] % 60);
    printf("%02d:%02d\n", wintime[2] / 60, wintime[2] % 60);

    return 0;
}