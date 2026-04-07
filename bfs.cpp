// Breadth First Search(for 0 based indexing)
vector<int> BFSTraversal(int v, vector<int> adj[])
{
    vector<int> vis(v, 0);
    vector<int> bfs;
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
