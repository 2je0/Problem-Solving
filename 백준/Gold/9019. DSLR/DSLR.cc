#include<iostream>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

struct DSLR {
	int num;
	string str;
	DSLR(int a, string b) : num(a), str(b){}
};
int D(int num) {
	return (num * 2) % 10000;
	
}
int S(int num) {
	if (num == 0) num = 9999;
	else num--;
	return num;
}
int L(int num) {
	int f = num / 1000;
	num %= 1000;
	num *= 10;
	num += f;
	return num;
}
int  R(int num) {
	int f = num % 10;
	num /= 10;
	num += 1000 * f;
	return num;
}
bool arr[10000];
int main() {
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(arr, false, sizeof(arr));
		int A, B;
		cin >> A >> B;
		queue<DSLR> q;
		q.push(DSLR(A, ""));
		arr[A] = true;
		while (!q.empty()) {
			DSLR now = q.front();
			int now_num = now.num;
			string now_str = now.str;
			if (now_num == B) {
				cout << now.str << '\n';
				break;
			}
			q.pop();
			int nextD = D(now_num);
			if (!arr[nextD]) {
				arr[nextD] = true;
				q.push(DSLR(nextD, now_str + "D"));
			}
			int nextS = S(now_num);
			if (!arr[nextS]) {
				arr[nextS] = true;
				q.push(DSLR(nextS, now_str + "S"));
			}
			int nextL = L(now_num);
			if (!arr[nextL]) {
				arr[nextL] = true;
				q.push(DSLR(nextL, now_str + "L"));
			}
			int nextR = R(now_num);
			if (!arr[nextR]) {
				arr[nextR] = true;
				q.push(DSLR(nextR, now_str + "R"));
			}
		}
	}

	return 0;
}