#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<stdexcept>
#include<limits>
#include<algorithm>
using namespace std;

const int maxVertices = 100;

class GraphNode
{
public:
    int vertex;
    int weight;
    GraphNode *next;

    GraphNode()
    {
        vertex = 0;
        weight = 0;
        next = nullptr;
    }

    GraphNode(int v, int w)
    {
        vertex = v;
        weight = w;
        next = nullptr;
    }
};

class Graph
{
    GraphNode *headnodes[maxVertices];
    // isse simple vertex count return krwana ha
    int n;
    bool visited[maxVertices];

public:
    Graph()
    {
        n = 0;
        for (int i = 0; i < maxVertices; i++)
        {
            headnodes[i] = nullptr;
            visited[i] = false;
        }
    }

    ~Graph()
    {
        for (int i = 0; i < n; i++)
        {
            GraphNode *current = headnodes[i];
            while (current != nullptr)
            {
                GraphNode *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    void create()
    {
        cout << "Enter the number of vertices: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            headnodes[i] = nullptr;
        }
        int edges;
        cout << "Enter the number of edges: ";
        cin >> edges;
        for (int i = 0; i < edges; i++)
        {
            int vertex1, vertex2, weight;
            cout << "Enter edge (u, v) and weight: ";
            cin >> vertex1 >> vertex2 >> weight;
            addEdge(vertex1, vertex2, weight);
        }
    }

    void initialize_visited()
    {

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
    }

    void addVertex(int vertex)
    {
        if (vertex >= maxVertices)
        {
            cout << "Vertex index out of bounds.\n";
            return;
        }
        if (vertex < n)
        {
            cout << "Vertex already exists.\n";
            return;
        }
        n++;

        cout << "Vertex " << vertex << " added\n";
    }

    void removeVertex(int vertex)
    {
        if (!vertexExists(vertex))
        {
            cout << "Vertex " << vertex << " does not exist.\n";
            return;
        }

        for (int i = 0; i < n; i++)
        {
            removeEdge(i, vertex);
        }

        GraphNode *current = headnodes[vertex];
        while (current != nullptr)
        {
            GraphNode *temp = current;
            current = current->next;
            delete temp;
        }
        headnodes[vertex] = nullptr;

        cout << "Vertex " << vertex << " removed.\n";
    }

    void addEdge(int vertex1, int vertex2, int weight)
    {
        if (!vertexExists(vertex1) || !vertexExists(vertex2))
        {
            cout << "Invalid vertices.\n";
            return;
        }

        GraphNode *newNode = new GraphNode(vertex2, weight);
        newNode->next = headnodes[vertex1];
        headnodes[vertex1] = newNode;

        cout << "Edge added from " << vertex1 << " to " << vertex2 << " with weight " << weight << ".\n";
    }

    void removeEdge(int vertex1, int vertex2)
    {
        if (!vertexExists(vertex1))
        {
            cout << "Vertex " << vertex1 << " does not exist.\n";
            return;
        }

        GraphNode *current = headnodes[vertex1];
        GraphNode *prev = nullptr;

        while (current != nullptr && current->vertex != vertex2)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Edge not found.\n";
            return;
        }

        if (prev == nullptr)
        {
            headnodes[vertex1] = current->next;
        }
        else
        {
            prev->next = current->next;
        }

        delete current;
        cout << "Edge from " << vertex1 << " to " << vertex2 << " removed.\n";
    }

    bool vertexExists(int vertex)
    {
        return vertex >= 0 && vertex < n;
    }

    int examine_n() const
    {
        return n;
    }

    int getWeight(int vertex1, int vertex2)
    {
        if (!vertexExists(vertex1) || !vertexExists(vertex2))
        {
            cout << "Invalid vertices.\n";
            return -1;
        }

        GraphNode *temp = headnodes[vertex1];
        while (temp != nullptr)
        {
            if (temp->vertex == vertex2)
            {
                return temp->weight;
            }
        }
        return 0;
    }

    void printGraph()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ": ";
            GraphNode *current = headnodes[i];
            while (current != nullptr)
            {
                cout << "(" << current->vertex << ", " << current->weight << ") -> ";
                current = current->next;
            }
            cout << "null\n";
        }
    }
};

int main()
{
    Graph graph;

    graph.create();

    cout << "Graph representation:\n";
    graph.printGraph();

    cout << "Enter u and v to get edge weight between them: \n";
    int u, v;
    cin >> u >> v;

    int weight = graph.getWeight(u, v);
    cout << weight << "\n";

    return 0;
}
