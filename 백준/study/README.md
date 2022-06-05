## 입력이 계속해서 이어질 때

```
while (scanf("%d", &n) != EOF)
while (cin >> n) // cin으로는 이렇게 하면 됩니다
```

## getline

제가 아까 cin이 개행문자를 구분해서 받는다고 했죠? 그렇다면 “엄준식 화이팅” 이런 문자열은 어떻게
한번에 받을 수 있을까요? 이럴 땐 getline으로 받으면 됩니다. 아래의 코드는 정답 코드입니다.

```
#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
getline(cin, s);
return 0;
}
```

## 실수형 출력

만약 cout을 사용해 정수부분 + 소수부분 해서 6자리까지 출력한다면 어떻게 해야할까요? (소수부분은
반올림)

```
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double a = 1.23456789;
int main(){
cout << a << "\n"; // 1.23457
cout.precision(7);
cout << a << "\n"; // 1.234568
return 0;
}
```

이렇게 precision을 통해 정해주면 됩니다.
