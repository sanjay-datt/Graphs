// Number of Provinces
class Solution
{
private:
    // Function to perform DFS traversal
    void dfs(int node, vector<int> adjList[], int visited[])
    {
        // Mark current node as visited
        visited[node] = 1;

        // Visit all adjacent unvisited nodes
        for (auto neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adjList, visited);
            }
        }
    }

public:
    // Function to count number of connected components
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // Create adjacency list from adjacency matrix
        vector<int> adjList[V];

        // Convert matrix to list
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // Ignore self-loops
                if (adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int visited[V] = {0};

        int count = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(i, adjList, visited);
            }
        }

        return count;
    }
};
