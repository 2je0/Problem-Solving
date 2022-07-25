#include<iostream>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;
int check[26];
vector<string> arr;
int r, c, res=0;
int d_x[4] = { 1,-1,0,0 };
int d_y[4] = { 0,0,1,-1 };
void DFS(int i, int j, int cnt) {
	//cout << i << " " << j << " " << cnt << endl;
	int idx = arr[i][j] - 'A'; // arr[0] -> A: 0이 idx

	if (check[idx] == 1) { //한번 방문한 적이 있던 곳이라면
		res = max(cnt, res);
		//cout << "return" << endl;
		return;
	}
	else {
		//cout << arr[i][j] << " ";
		//cout << i << " " << j << endl;
		for (int k = 0; k < 4; k++) {
			int new_i = i + d_x[k];
			int new_j = j + d_y[k];
			if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c) {
				check[idx] = 1;
				DFS(new_i, new_j, cnt + 1);
				check[idx] = 0;
			}

		}
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);

	cin >> r >> c;
	cin.ignore();

	arr.resize(r);
	for (int i = 0; i < r; i++) {
		getline(cin, arr[i]);
	}
	DFS(0, 0, 0);
	cout << res << endl;


	return 0;
}