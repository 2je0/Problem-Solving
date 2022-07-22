#include<iostream>
#include<cmath>
using namespace std;
bool check[10];
char inequal[10];
int n;
long long maxx = 0, minn = 9876543210;

void DFS(int level, int last, long long sum) {
	if (level == n + 1) {
		if (sum > maxx) maxx = sum;
		if (sum < minn) minn = sum;
	}
	else {
		if (level == 0) {
			for (int i = 0; i < 10; i++) {
				if (!check[i]) {
					check[i] = true;
					DFS(level + 1, i, sum * 10 + i);
					check[i] = false;
				}
			}
		}
		else {
			for (int i = 0; i < 10; i++) {
				if (!check[i]) {	//아직 안고른 숫자 고름
					if (inequal[level] == '>') {
						if (last > i) {
							check[i] = true;
							DFS(level + 1, i, sum * 10 + i);
							check[i] = false;
						}
					}
					else if (inequal[level] == '<') {
						if (last < i) {
							check[i] = true;
							DFS(level + 1, i, sum * 10 + i);
							check[i] = false;
						}
					}
				}
			}
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	for (int i = 0; i < 10; i++) check[i] = false;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inequal[i];
	}
	DFS(0, 0, 0);
	if (maxx < pow(10, n)) cout << 0;
	cout << maxx << endl;
	if (minn < pow(10, n)) cout << 0;
	cout << minn << endl;
	return 0;
}