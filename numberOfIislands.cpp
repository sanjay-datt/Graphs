// Number of Distinct Islands | Constructive Thinking + DFS

class sol
{
private:
    void dfs(int row, int col, const vector<vector<int>> &grid, vector<vector<int>> &vis,
             vector<pair<int, int>> &vec, int row0, int col0)
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        vec.push_back({row - row0, col - col0});
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newR = delRow[i] + row;
            int newC = delCol[i] + col;
            if (newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == 1 && !vis[newR][newC])
            {
                dfs(newR, newC, grid, vis, vec, row0, col0);
            }
        }
    }

public:
    int numberOfDistinctIslands(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
