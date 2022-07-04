#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 104
using namespace std;
int arr[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int res = 1;
int n;
void dfs(int x, int y, int water)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny])
            continue;
        if (arr[nx][ny] > water)
        {
            visited[nx][ny] = 1;
            dfs(nx, ny, water);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> n;
    int maxx = -1, minn = 200;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            maxx = max(maxx, arr[i][j]);
            minn = min(minn, arr[i][j]);
        }
    }
    for (int i = minn; i < maxx; i++)
    {
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (arr[j][k] > i && !visited[j][k])
                {
                    cnt++;
                    dfs(j, k, i);
                }
            }
        }
        res = max(res, cnt);
    }
    cout << res;

    return 0;
}