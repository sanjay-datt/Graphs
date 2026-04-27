// Shortest Path in Undirected Graph with Unit Weights from given source.
vector<int> shortestDist(vector<vector<int>> &edges, int n, int m, int src)
{
    vector<int> adj[n];
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> dst(n, 1000000000);
    dst[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (dst[node] + 1 < dst[it])
            {
                dst[it] = dst[node] + 1;
                q.push(it);
            }
        }
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (dst[i] != 1000000000)
            ans[i] = dst[i];
    }
    return ans;
}
