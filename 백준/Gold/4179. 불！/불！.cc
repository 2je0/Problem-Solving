#include<iostream>
#include<queue>
#define MAX 1001
int R, C;
char map1[MAX][MAX];
char map2[MAX][MAX];
int firemap[MAX][MAX];
bool check[MAX][MAX];
bool check_fire[MAX][MAX];
int d_x[4] = { 0,0,1,-1 };
int d_y[4] = { 1,-1,0,0 };
int Gtime = -1;
int ans=-1;

struct J {
	int r;
	int c;
};
struct Q {
	int r;
	int c;
	int time;
};
using namespace std;
queue<Q> fireQ;
void fire() {
	while (!fireQ.empty()) {
		int now_r = fireQ.front().r;
		int now_c = fireQ.front().c;
		int now_time = fireQ.front().time;
		fireQ.pop();
		if (now_r >= 0 && now_r < R && now_c >= 0 && now_c < C) {
			for (int i = 0; i < 4; i++) {
				int next_r = now_r + d_x[i];
				int next_c = now_c + d_y[i];
				int next_time = now_time + 1;
				if (check_fire[next_r][next_c] == false && next_r >= 0 && next_r < R && next_c >= 0 && next_c < C && map1[next_r][next_c] == '.') {
					firemap[next_r][next_c] = next_time;
					check_fire[next_r][next_c] = true;
					fireQ.push({ next_r,next_c,next_time });
				}
			}
		}

	}
}
void printMap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << firemap[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;
	J jh;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			firemap[i][j] = 987654321;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map1[i][j];
			if (map1[i][j] == 'J') {
				jh.r = i; jh.c = j;
				map1[i][j] = '.';
			}
			if (map1[i][j] == 'F') {
				fireQ.push({ i,j,0 });
				check_fire[i][j] = 1;
			}
		}
	}
	fire();
	//printMap();

	queue<Q> q;
	q.push({ jh.r,jh.c,0 });
	check[jh.r][jh.c] = 1;
	while (!q.empty()) {
		int now_r = q.front().r;
		int now_c = q.front().c;
		int now_time = q.front().time;
		q.pop();
		if (now_r == 0 || now_r == R - 1 || now_c == 0 || now_c == C - 1) {
			ans = now_time;
			break;
		}
		//if (now_time != Gtime) {
		//	fire();
		//	//printMap();
		//	Gtime = now_time;
		//}
		for (int i = 0; i < 4; i++) {
			int next_r = now_r + d_x[i];
			int next_c = now_c + d_y[i];
			int next_time = now_time + 1;
			if (map1[next_r][next_c] == '.' && check[next_r][next_c] == false && next_time < firemap[next_r][next_c]) {
				check[next_r][next_c] = true;
				q.push({ next_r,next_c,next_time });
			}
			
		}

	}
	if (ans == -1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << ans+1;
	}



	return 0;
}