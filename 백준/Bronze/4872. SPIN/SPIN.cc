#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
int arr[10];

int main() {
	//freopen("input.txt", "r", stdin);
	char n[10];
	int size;
	while (scanf("%s", &n) != EOF){
		size = strlen(n);
		for (int i = 0; i < size; i++) {
			arr[i] += n[i] - '0';
		}
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i] % 10;
	}

	return 0;
}