#include <iostream>
#define MAX 200001
int arr[MAX];
int cnt[100001];
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int start = 0, end = -1;
	int ans = -1;
	while (1) {
		end++;
		if (end >= n)break;
		cnt[arr[end]]++;
		if (cnt[arr[end]] <= k) {

		}
		else if (cnt[arr[end]] > k) {
			while (1) {
				cnt[arr[start]]--;
				start++;
				if (cnt[arr[end]] <= k) break;
			}
		}
		ans = max(ans, end - start + 1);
		
	}
	cout << ans;


	return 0;
}