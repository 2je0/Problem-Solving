#include <bits/stdc++.h>
using namespace std;
int n;
int maxx;
int arr[10];
int main() {
    for(int i=1,num;i <=9;i++){
        cin >> num;
        if(num > maxx){
            n = i, maxx = num;
        }
    }
    cout << maxx << '\n' << n;
    return 0;
}