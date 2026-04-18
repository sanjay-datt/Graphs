// Course Schedule I and II | Pre-requisite Tasks | Topological Sort
// Course Schedule I is same as cycle detection in DG.
// But in Course Schedule II we have to return the orderings also
// this will be solved by mixing both previous solutions.
class CourseScheduleBFS
{
    vector<int> topoSort(int V, vector<vector<int>> &prerequisites)
    {
        vector<int> adj[V];
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        int indegree[V] = {0};
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        if (topo.size() == V)
            return topo;
        return {};
    }
};

class CourseScheduleDFS
{
    bool dfs(int node, vector<int> adj[], vector<bool> &visited,
             vector<bool> &inStack, stack<int> &st)
    {

        visited[node] = true;
        inStack[node] = true;

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                if (dfs(neighbour, adj, visited, inStack, st))
                    return true;
            }
            else if (inStack[neighbour])
            {
                return true;
            }
        }

        inStack[node] = false;
        st.push(node);
        return false;
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> inStack(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, inStack, st))
                    return {};
            }
        }
        vector<int> topo;
        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};
