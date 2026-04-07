//Implementation using Adjacency list.
class Graph
{
public:
    unordered_map<int, list<int>> adj_list;

    void addEdge(int u, int v, bool direction)
    {
        adj_list[u].push_back(v);

        // 0->undirected
        // 1->directed

        if (direction == 0)
            adj_list[v].push_back(u);
    }

    void printAdjList()
    {
        for (auto i : adj_list)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};


//Implementation using Adjacency matrix.
class Graph2
{
public:
    int n;
    vector<vector<int>> matrix;

    Graph2(int n)
    {
        this->n = n;
        matrix.assign(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v, bool directed = false, int weight = 1)
    {
        matrix[u][v] = weight;
        if (!directed)
            matrix[v][u] = weight;
    }

    void printMatrix()
    {
        cout << "  ";
        for (int i = 0; i < n; i++)
            cout << i << " ";
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            cout << i << " ";
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool hasEdge(int u, int v)
    {
        return matrix[u][v] != 0;
    }
};
