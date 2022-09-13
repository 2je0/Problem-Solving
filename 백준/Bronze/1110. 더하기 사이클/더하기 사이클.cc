#include <bits/stdc++.h>
using namespace std;
int n,cnt;
int addcycle( int num){
    int ret =0;
    int ten = num%10;
    while(num){
        ret += num%10;
        num/=10;
    }
    return ret%10 + ten*10;
}
int main(){
    cin >> n;
    int temp = n;
    while(1){
        temp = addcycle(temp);
        cnt++;
        if(n == temp) break;

    }
    cout << cnt;
}