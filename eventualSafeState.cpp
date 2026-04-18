// Find Eventual Safe States - BFS - Topological Sort
vector<int> eventualSafe(int v, vector<int> adj[])
{
    vector<int> adjRev[v];
    int inDeg[v] = {0};
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            adjRev[it].push_back(i);
            inDeg[i]++;
        }
    }
    queue<int> q;
    vector<int> safeNodes;
    for (int i = 0; i < v; i++)
    {
        if (inDeg[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for (auto it : adjRev[node])
        {
            inDeg[it]--;
            if (inDeg[it] == 0)
                q.push(it);
        }
    }
    // according to question we have to  return nodes in sorted order
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}
