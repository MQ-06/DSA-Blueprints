#include <iostream>
#include <limits>
#include "Graph.cpp"
using namespace std;

void menu()
{
    cout << "\nMenu: \n";
    cout << "1. Insert Edge\n";
    cout << "2. Delete Edge\n";
    cout << "3. Insert Vertex\n";
    cout << "4. Delete Vertex\n";
    cout << "5. Display Graph (Matrix form)\n";
    cout << "6. Check if an edge exists\n";
    cout << "7. Display List format\n";
    cout << "8. Display edges of a particular node/vertex\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    int vertex, choice;
    char directedChoice;

    cout << "Do you want a directed graph? (y/n): ";
    cin >> directedChoice;

    bool directed = (directedChoice == 'y' || directedChoice == 'Y');

    do
    {
        cout << "Enter number of vertices: ";
        cin >> vertex;

        if (vertex <= 0)
        {
            cout << "Number of vertices cannot be negative. Please try again." << endl;
        }
    } while (vertex <= 0);

    Graph g(vertex);
    g.setDirected(directed); 

    while (true)
    {
        menu();

        if (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number between 1 and 9.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice < 1 || choice > 9)
        {
            cout << "Invalid choice! Please enter a number between 1 and 9.\n";
            continue;
        }

        int u, v;

        switch (choice)
        {
        case 1:
            cout << "Enter the vertices (u v) to insert an edge: ";
            cin >> u >> v;
            try
            {
                g.insertEdge(u, v);
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 2:
            cout << "Enter the vertices (u v) to delete the edge: ";
            cin >> u >> v;
            try
            {
                g.deleteEdge(u, v);
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 3:
            g.insertVertex();
            cout << "Vertex inserted successfully!" << endl;
            break;

        case 4:
            cout << "Enter the vertex index to delete: ";
            cin >> v;
            try
            {

                g.deleteVertex(v);
                cout << "Vertex " << v << " deleted successfully!" << endl;
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 5:
            g.displayGraph();
            break;

        case 6:
            cout << "Enter the vertices (u v) to check if the edge exists: ";
            cin >> u >> v;
            try
            {
                if (g.edgeExists(u, v))
                {
                    cout << "Edge exists between " << u << " and " << v << endl;
                }
                else
                {
                    cout << "Edge does not exist between " << u << " and " << v << endl;
                }
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 7:
            g.displayList();
            break;

        case 8:
            cout << "Enter the node to see edges of: ";
            cin >> u;
            try
            {
                g.displayEdgesOfANode(u);
            }
            catch (const exception &e)
            {
                cout << e.what() << endl;
            }

            break;

        case 9:
            cout << "Exiting program..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }

    return 0;
}
