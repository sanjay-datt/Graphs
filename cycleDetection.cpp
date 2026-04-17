// Cycle Detection in Directed Graph using DFS
class CycleDetection
{
private:
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (checkCycle(it, adj, vis, dfsVis))
                    return true;
            }
            else if (dfsVis[it])
                return true;
        }
        dfsVis[node] = 0;
        return false;
    }

public:
    bool isCycle(int n, vector<int> adj[])
    {
        int vis[n] = {0}, dfsVis[n] = {0};
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, adj, vis, dfsVis))
                    return true;
            }
        }
        return false;
    }
};
