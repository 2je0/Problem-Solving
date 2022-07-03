#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 54
using namespace std;
int arr[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int m, n;
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
            continue;
        if (arr[nx][ny])
        {
            visited[nx][ny] = 1;
            arr[nx][ny] = 0;
            dfs(nx, ny);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++)
    {
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        int k, cnt = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j])
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}