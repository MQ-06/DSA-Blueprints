#include "Graph.h"

Graph::Graph() : matrix(nullptr), vertex(0), edge(0), directed(false) {}

Graph::Graph(int vertex, int edges) : vertex(vertex), edge(edges), directed(false)
{
    matrix = new int *[vertex];
    for (int i = 0; i < vertex; i++)
    {
        matrix[i] = new int[vertex];
        for (int j = 0; j < vertex; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Graph::Graph(int vertex) : vertex(vertex), edge(0), directed(false)
{
    matrix = new int *[vertex];
    for (int i = 0; i < vertex; i++)
    {
        matrix[i] = new int[vertex];
        for (int j = 0; j < vertex; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Graph::~Graph()
{
    if (matrix != nullptr)
    {
        for (int i = 0; i < vertex; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

Graph::Graph(const Graph &other)
{
    this->vertex = other.vertex;
    this->edge = other.edge;
    this->directed = other.directed;
    matrix = new int *[vertex];
    for (int i = 0; i < vertex; i++)
    {
        matrix[i] = new int[vertex];
        for (int j = 0; j < vertex; j++)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

void Graph::setDirected(bool dir)
{
    directed = dir;
}

bool Graph::isDirected() const
{
    return directed;
}

void Graph::insertEdge(int u, int v)
{
    if (u < 0 || u >= vertex || v < 0 || v >= vertex)
    {
        throw invalid_argument("Invalid vertex!");
    }

    if (matrix[u][v] == 1)
    {
        cout << "Edge already exists between " << u << " and " << v << endl;
    }
    else
    {
        matrix[u][v] = 1;
        if (!directed)
        {
            matrix[v][u] = 1;
        }
        edge++;
        cout << "Edge inserted between " << u << " and " << v << endl;
    }
}

void Graph::deleteEdge(int u, int v)
{
    if (u < 0 || u >= vertex || v < 0 || v >= vertex)
    {
        throw invalid_argument("Invalid vertex!");
    }

    if (matrix[u][v] == 0)
    {
        cout << "No edge exists between " << u << " and " << v << " to delete." << endl;
    }
    else
    {
        matrix[u][v] = 0;
        if (!directed)
        {
            matrix[v][u] = 0;
        }
        edge--;
        cout << "Edge deleted between " << u << " and " << v << endl;
    }
}

void Graph::insertVertex()
{
    vertex += 1;
    int **new_matrix = new int *[vertex];
    for (int i = 0; i < vertex; i++)
    {
        new_matrix[i] = new int[vertex];
        for (int j = 0; j < vertex; j++)
        {
            if (i < vertex - 1 && j < vertex - 1)
            {
                new_matrix[i][j] = matrix[i][j];
            }
            else
            {
                new_matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < vertex - 1; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = new_matrix;
}

void Graph::deleteVertex(int v)
{
    if (v < 0 || v >= vertex)
    {
        throw invalid_argument("Invalid vertex!");
    }

    vertex -= 1;

    int **new_matrix = new int *[vertex];
    for (int i = 0, new_i = 0; i < vertex + 1; i++)
    {
        if (i == v)
            continue;

        new_matrix[new_i] = new int[vertex];
        for (int j = 0, new_j = 0; j < vertex + 1; j++)
        {
            if (j == v)
                continue;

            new_matrix[new_i][new_j] = matrix[i][j];
            new_j++;
        }
        new_i++;
    }

    for (int i = 0; i < vertex + 1; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = new_matrix;
}

void Graph::displayGraph()
{
    if (vertex == 0)
    {
        cout << "Graph is empty." << endl;
        return;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::displayEdgesOfANode(int v)
{
    if (v < 0 || v >= vertex)
    {
        throw invalid_argument("Invalid vertex!");
    }

    cout << "Edges connected to Node " << v << " are:\n";
    bool hasEdges = false;
    for (int i = 0; i < vertex; i++)
    {
        if (matrix[v][i] == 1)
        {
            cout << "(" << v << "," << i << ")" << endl;
            hasEdges = true;
        }
    }
    if (!hasEdges)
    {
        cout << "No edges connected to this node.\n";
    }
}

void Graph::displayList()
{
    if (vertex == 0)
    {
        cout << "No list to display!\n";
        return;
    }

    cout << "Displaying Adjacency List:\n";

    bool hasEdge = false;
    for (int i = 0; i < vertex; i++)
    {
        cout << "Node " << i << " is connected to: ";
        hasEdge = false;
        for (int j = 0; j < vertex; j++)
        {
            if (matrix[i][j] == 1)
            {
                cout << j;
                if (j != vertex - 1)
                {
                    cout << " , ";
                }
                hasEdge = true;
            }
        }

        if (!hasEdge)
        {
            cout << "No connections";
        }
        cout << endl;
    }
}

int Graph ::totalEdges() const { return edge; }
int Graph ::totalVertices() const { return vertex; }

bool Graph ::edgeExists(int u, int v)
{
    if (v < 0 || v >= vertex)
    {
        throw invalid_argument("Invalid vertex!");
    }

    return (matrix[u][v] == 1) ;
}
