#include <iostream>

using namespace std;
int arr[10001];

int self(int n) {
	int sum = n;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	if (sum > 10000) return 0;
	return sum;
}
int main() {
	int cnt = 0;
	
	for (int i = 1; i < 10001; i++) {
		arr[self(i)] = 1;
	}
	
	for (int i = 1; i < 10001; i++) {
		if (arr[i] == 0) cout << i << endl;
	}

	return 0;
}