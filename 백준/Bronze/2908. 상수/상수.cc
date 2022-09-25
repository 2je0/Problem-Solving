#include<bits/stdc++.h>
using namespace std;
int flag;
int main(){
    string a[2];
    cin >> a[0] >>a[1];
    for(int i=2;i>=0;i--){
        if(a[0][i]>a[1][i]){
            flag = 0;
            break;
        }
        else if (a[0][i]==a[1][i])continue;
        else {flag = 1; break;}
    }
    for(int i=2;i>=0;i--){
        cout << a[flag][i];
    }
    return 0;
}