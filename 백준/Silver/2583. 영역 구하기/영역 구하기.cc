#include <bits/stdc++.h>
#define MAXN 104
#define endl '\n';
int arr[MAXN][MAXN];
int visited[MAXN][MAXN];
int m, n, k;
int numOfSqure, numOfSection;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
using namespace std;
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
            continue;
        if (!arr[nx][ny])
        {
            numOfSqure++;
            visited[nx][ny] = 1;
            dfs(nx, ny);
        }
    }
}
int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j < c; j++)
        {
            for (int l = b; l < d; l++)
            {
                arr[l][j]++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!arr[i][j] && !visited[i][j])
            {
                numOfSqure = 0;
                numOfSection++;
                visited[i][j] = 1;
                dfs(i, j);
                pq.push(numOfSqure + 1);
            }
        }
    }
    cout << numOfSection << endl;
    while (!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
    return 0;
}