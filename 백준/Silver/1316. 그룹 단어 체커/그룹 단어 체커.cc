#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int main(){
    cin >> n;
    while(n--){
        string a;
        bool flag = true;
        char arr[26] = {0,};
        cin >> a;
        for(int i=0; i< a.size();i++){
            if(arr[a[i]-'a'] == 0 ) {
                while(a[i] == a[i+1]){
                    i++;
                }
                arr[a[i]-'a'] = 1;
            }
            else {
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
    }
    cout << cnt;
    return 0;
}