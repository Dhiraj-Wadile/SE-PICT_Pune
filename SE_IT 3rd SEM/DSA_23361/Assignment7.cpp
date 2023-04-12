#include <iostream>
using namespace std;
#define v 5

class Graph
{
public:
    int arr[5][5];
    int parent[5];
    // Constructor
    Graph()
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    // Function to take input for graph
    void acceptData()
    {
        int v1, v2, w, e;
        cout << "Enter no of edges: ";
        cin >> e;
        for (int i = 0; i < e; i++)
        {
            cout << "\nEnter strating point(0 to 5): ";
            cin >> v1;
            cout << "\nEnter ending point(0 to 5): ";
            cin >> v2;
            cout << "\nEnter weight: ";
            cin >> w;
            cout << endl;
            arr[v1][v2] = w;
            arr[v2][v1] = w;
        }
    }
    // Function to display graph
    void display()
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    // Function to find MST by Prim's Algorithm
    void findMSTPrims()
    {
        bool selected[5] = {false, false, false, false, false};
        int edge = 0;
        // Setting first vertex as visited vertex
        selected[0] = true;
        while (edge < v - 1)
        {
            int minWeight = 999;
            // Indices for iterating
            int x, y = 0;
            for (int i = 0; i < v; i++)
            {
                if (selected[i])
                {
                    for (int j = 0; j < v; j++)
                    {
                        if (!selected[j] && arr[i][j] != 0 && arr[i][j] < minWeight)
                        {
                                minWeight = arr[i][j];
                                x = i;
                                y = j;
                            
                        }
                    }
                }
            }
            selected[y] = true;
            cout << x << "," << y << " " << minWeight << endl;
            edge++;
        }
        cout << "\nEdges: " << edge;
    }

    // Find set of vertex i
    int findParent(int a)
    {
        while (parent[a] != a)
        {
            a = parent[a];
        }
        return a;
    }
    // Does union of i and j. It returns
    // false if i and j are already in same
    // set.
    void setUnion(int x, int y)
    {
        x = findParent(x);
        y = findParent(y);
        parent[x] = y;
    }
    // Function to find MST by Krushkal's Algorithm
    void findMSTKrushkals()
    {
        // Initialize sets of disjoint sets.
        for (int k = 0; k < v; k++)
        {
            parent[k] = k;
        }
        int edge = 0;
        while (edge < v - 1)
        {
            int minWeight = 999;
            // Indices for iterating
            int x, y = 0;
            int i, j;
            for (i = 0; i < v; i++)
            {
                for (j = 0; j < v; j++)
                {
                    if ((findParent(i) != findParent(j)) && (arr[i][j] < minWeight) && (arr[i][j] != 0))
                    {
                        minWeight = arr[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
            setUnion(x, y);
            edge++;
            cout << x << "," << y << " " << minWeight << endl;
        }
    }
};

// Driver code
int main()
{
    // Instance of class Graph
    Graph obj;
    int choice;

    do
    {
        cout << "------Minimum Spanning Tree------";
        cout << "\n1.Create Graph";
        cout << "\n2.Display Graph";
        cout << "\n3.Prim's Algorithm";
        cout << "\n4.Krushkal's Algorithm";
        cout << "\n5.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.acceptData();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            cout << "\nMST using prims algo: " << endl;
            obj.findMSTPrims();
            break;
        case 4:
            cout << "\nMST using Kruskals algo: " << endl;
            obj.findMSTKrushkals();
            break;
        case 5:
            cout << "\nExiting program!";
            break;
        default:
            break;
        }
    } while (choice < 4);

    return 0;
}