#include<bits/stdc++.h>
using namespace std;
int arr[] = {1,1,2,2,2,8};
int main(){
    for(int i=0,temp;i<6;i++){
        cin >> temp;
        cout << arr[i] - temp << ' ';
    }
    return 0;
}