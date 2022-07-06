#include <bits/stdc++.h>

using namespace std;
bool isMo(char temp) {
    if (temp == 'a' || temp == 'i' || temp == 'u' || temp == 'e' || temp == 'o')
        return true;
    else
        return false;
}
int main() {
    while (1) {
        string input;
        cin >> input;
        if (input == "end") break;
        char before = 0, before2 = 0;
        int mo = 0;
        bool valid = true;
        for (char& temp : input) {
            if (temp == 'a' || temp == 'i' || temp == 'u' || temp == 'e' || temp == 'o') mo = 1;
            if (before == temp) {
                if (temp == 'o' || temp == 'e')
                    continue;
                else {
                    valid = false;
                    break;
                }
            }
            if (before2) {
                if (isMo(before2) && isMo(before) && isMo(temp)) {
                    valid = false;
                    break;
                }
                if (!isMo(before2) && !isMo(before) && !isMo(temp)) {
                    valid = false;
                    break;
                }
            }

            before2 = before;
            before = temp;
        }
        if (!mo) valid = false;
        if (valid)
            cout << '<' << input << '>' << " is acceptable." << '\n';
        else
            cout << '<' << input << '>' << " is not acceptable." << '\n';
    }
    return 0;
}