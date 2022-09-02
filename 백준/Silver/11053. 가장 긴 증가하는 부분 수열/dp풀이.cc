#include<iostream>

using namespace std;
int input[1000];
int dp[1000];
int main() {
	//freopen("input.txt", "r", stdin);
	int n,res =-1;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> input[i];
	for (int i = 0; i < n; i++) {
		int maxx = 0;
		for (int j = 0; j < i; j++) {
			if (input[i] > input[j]) {
				if (dp[j] > maxx) maxx = dp[j];
			}
		}
		dp[i] = maxx + 1;
	}

	for (int i = 0; i < n; i++) {
		if (dp[i] > res) res = dp[i];
	}
	cout << res << endl;
	return 0;
}
