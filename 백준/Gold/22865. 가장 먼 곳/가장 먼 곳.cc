#include<iostream>
#include<vector>
#include<queue>
#define INF	987654321
using namespace std;
vector < vector<pair<int, int>> > map;
vector<vector<int >> cost;
struct box {
	int first;
	int second;
	box(int a,int b) : first(a), second(b){}
	bool operator< (const box& b)const {
		return second > b.second;
	}
};
void route(int num,int idx) {
	cost[num][idx] = 0;
	priority_queue<box> q;
	q.push({ num,0 });
	while (!q.empty()) {
		int now_pos = q.top().first;
		int now_cost = q.top().second;
		q.pop();
		if (now_cost > cost[now_pos][idx]) continue;
		for (auto& ele : map[now_pos]) {
			int next_pos = ele.first;
			int next_cost = now_cost + ele.second;
			if (next_cost < cost[next_pos][idx]) {
				cost[next_pos][idx] = next_cost;
				q.push({ next_pos,next_cost });
			}
		}
	}

}
int main() {
	//freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	int A, B, C;
	scanf("%d %d %d", &A,&B,&C);
	int M; //cin >> M;
	scanf("%d", &M);
	map.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}
	cost.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cost[i].resize(4);
		for (int j = 0; j < 3; j++) cost[i][j] = INF;
	}
	
	route(A, 0);
	route(B, 1);
	route(C, 2);
	int maxx = -1;
	int maxidx = -1;
	for (int i = 1; i <= N; i++) {
		int minn = cost[i][0];
		for (int j = 1; j < 3; j++) {
			minn = min(minn, cost[i][j]);
		}
		cost[i][3] = minn;
		if (minn > maxx) {
			maxx = minn;
			maxidx = i;
		}
	}
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		if (cost[i][j] == INF) cout << 0 << " ";
	//		else
	//		cout << cost[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	cout << maxidx;
	

	return 0;
}