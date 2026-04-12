// Bipartite Graph
//BFS Technique
class Bipartite_Sol
{
private:
    bool bfs(int start, int v, vector<int> adj[], vector<int> &color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipertite(int v, vector<int> adj[])
    {
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (bfs(i, v, adj, color) == false)
                    return false;
            }
        }
        return true;
    }
};

//DFS Technique
class Bipartite
{
private:
    bool dfs(int node, int col, vector<int> adj[], vector<int> &color)
    {
        color[node] = col;
        for(auto it: adj[node]){
            if(color[it] == -1){
                if(dfs(it, !col, adj, color)==false) return false;
            }
            else if(color[it] == col) return false;
        }
        return true;
    }

public:
    bool isBipertite(int v, vector<int> adj[])
    {
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, adj, color) == false)
                    return false;
            }
        }
        return true;
    }
};
