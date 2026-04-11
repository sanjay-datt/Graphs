// Number of Enclaves | Multi-source BFS
int numberOfEnclaves(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newR = delRow[i] + r;
            int newC = delCol[i] + c;
            if (newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == 1 && !vis[newR][newC])
            {
                vis[newR][newC] = 1;
                q.push({newR, newC});
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}
