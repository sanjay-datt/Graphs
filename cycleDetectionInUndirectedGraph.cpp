// Detect a Cycle in an Undirected Graph using BFS
bool detect(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }
            else if (parent != adjNode)
                return true;
        }
    }
    return false;
}

bool detectCycle(int v, vector<int> adj[])
{
    int vis[v] = {0};
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis))
                return true;
        }
    }
    return false;
}

// Detect a Cycle in an Undirected Graph using DFS
bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
        {
            if (dfs(adjNode, node, adj, vis) == true)
                return true;
        }
        else if (adjNode != parent)
            return true;
    }
    return false;
}

bool isCycle(int v, vector<int> adj[])
{
    vector<int> vis(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis) == true)
                return true;
        }
    }
    return false;
}
