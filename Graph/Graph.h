#include <iostream>
#include <stdexcept>
using namespace std;

class Graph
{
private:
    int **matrix;
    int vertex, edge;
    bool directed; 

public:
    Graph(); 
    Graph(int vertex, int edges); 
    Graph(int vertex); 
    ~Graph(); 
    Graph(const Graph &other); 

    bool edgeExists(int u, int v);
    void insertEdge(int u, int v);
    void deleteEdge(int u, int v);
    void insertVertex();
    void deleteVertex(int v);
    void displayGraph();
    void displayEdgesOfANode(int v);
    void displayList();
    int totalEdges() const;
    int totalVertices() const;

    void setDirected(bool dir); 
    bool isDirected() const; 
};
