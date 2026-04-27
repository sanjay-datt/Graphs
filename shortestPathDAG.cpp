// Shortest Path in Directed Acyclic Graph - Topological Sort
class DAGShortestPath
{
private:
    void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
                topoSort(v, adj, vis, st);
        }
        st.push(node);
    }

public:
    vector<int> shortestPathDAG(int n, int m, vector<int> edges[])
    {
        vector < pair<int, int>> adj[n];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        int vis[n] = {0};
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                topoSort(i, adj, vis, st);
        }

        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[0] = 0; // We are taking 0 as source node in this solution
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (dist[node] == INF) continue;
            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[v])
                    dist[v] = dist[node] + wt;
            }
        }
        for (int i = 0; i < n; i++) if (dist[i] == INF) dist[i] = -1;
        return dist;
    }
};
