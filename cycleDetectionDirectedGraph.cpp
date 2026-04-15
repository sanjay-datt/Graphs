class CycleDetection
{

private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[])
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[it])
                return true;
        }
        pathVis[node] = 0;
        return false;
    }

public:
    bool isCycle(int v, vector<int> adj[])
    {
        int vis[v] = {0};
        int pathVis[v] = {0};

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, pathVis))
                    return true;
            }
        }
        return false;
    }
};
