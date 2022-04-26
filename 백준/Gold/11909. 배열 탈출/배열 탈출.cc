#include<iostream>
#include<queue>
#define MAX 2223
#define INF	2147000000
using namespace std;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
struct box {
	box(int a,int b, int c) : i(a),j(b),cost(c){}
	int i;
	int j;
	int cost;
	bool operator < (const box& b) const {
		return cost > b.cost;
	}
};
int n;
int map[MAX][MAX];
int cost[MAX][MAX];
int main() {
	//freopen("input.txt", "r", stdin);
	//cin >> n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//cin >> map[i][j];
			scanf("%d", &map[i][j]);
			cost[i][j] = INF;
		}
	}
	priority_queue<box> q;
	q.push(box(1, 1, 0));
	while (!q.empty()) {
		int now_i = q.top().i;
		int now_j = q.top().j;
		int now_cost = q.top().cost;
		q.pop();
		for (int i = 0; i < 2; i++) {
			int next_i = now_i + dx[i];
			int next_j = now_j + dy[i];
			int next_cost;
			//cout << "next_i: " << next_i << " / next_j: " << next_j << " / cost: " << next_cost << endl;
			if (next_i > n || next_j > n) continue;
			if (map[now_i][now_j] > map[next_i][next_j]) next_cost = now_cost;
			else next_cost = now_cost + (map[next_i][next_j] - map[now_i][now_j]) + 1;
			if (next_cost < cost[next_i][next_j]) {
				cost[next_i][next_j] = next_cost;
				if (next_i == n && next_j == n) break;
				q.push(box(next_i, next_j, next_cost));
			}
		}
	}
	cout << cost[n][n];

	return 0;
}