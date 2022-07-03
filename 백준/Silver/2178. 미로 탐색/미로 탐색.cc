#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int arr[104][104];
int visited[104][104];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == n && y == m)
        {
            printf("%d", visited[x][y]);
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > 100 || ny < 1 || ny > 100)
                continue;
            if (!visited[nx][ny] && arr[nx][ny])
            {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
  
    return 0;
}