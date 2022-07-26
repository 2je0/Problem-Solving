#include<iostream>
#include <vector>
#include<algorithm>
#define MAX 101
#define endl '\n'

using namespace std;
bool visited[MAX];
vector<vector<int>> map;
vector<int> blue;
vector<int> white;
void DFS(int level, int v) {
	for (auto& ele : map[v]) {
		if (!visited[ele]) {
			visited[ele] = true;
			if (level & 1) {
				blue.push_back(ele);
			}
			else white.push_back(ele);
			DFS(level+1,ele);
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	int n; cin >> n;
	map.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			map[i].push_back(b);
			map[b].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			blue.push_back(i);
			DFS(0, i);
		}
	}
	sort(blue.begin(), blue.end());
	sort(white.begin(), white.end());
	cout << blue.size() << endl;
	for (auto& ele : blue) cout << ele << " ";
	cout << endl;
	cout << white.size() << endl;
	for (auto& ele : white) cout << ele << " ";
	cout << endl;
}