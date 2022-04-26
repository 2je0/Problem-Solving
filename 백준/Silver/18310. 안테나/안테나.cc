#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#define MAX 200000
using namespace std;
int arr[MAX];

int main() {
	//freopen("input.txt", "r", stdin);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	if (n & 1) { //홀수
		cout << arr[n / 2];
	}
	else {
		cout << arr[(n / 2) - 1];
	}
	return 0;
}