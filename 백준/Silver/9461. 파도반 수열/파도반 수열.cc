#include<bits/stdc++.h>

using namespace std;
long long arr[101] = {0,1,1,1,2,2,3};
int main(){
    // freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    for(int i=6;i<101;i++){
        arr[i] = arr[i-1]+arr[i-5];
    }
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        cout << arr[temp] << '\n';
    }
    return 0;
}