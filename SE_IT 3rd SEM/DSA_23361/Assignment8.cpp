/*Represent a graph of city using adjacency matrix /adjacency list. Nodes should represent the various
landmarks and links should represent the distance between them. Find the shortest path using
Dijkstra's algorithm from single source to all destination*/
#include <iostream>
using namespace std;
#define v 4

class Graph
{
public:
    int arr[4][4];
    int parent[4];
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

    void accept()
    {
        int e, w, s1, s2;
        cout << "Enter no of edges: ";
        cin >> e;
        for (int i = 0; i < e; i++)
        {
            cout << "Enter starting point: ";
            cin >> s1;
            cout << "Enter ending point: ";
            cin >> s2;
            cout << "Enter weight: ";
            cin >> w;
            arr[s1][s2] = w;
            arr[s2][s1] = w;
        }
    }

    void display()
    {
        cout << "\nAdjacency matrix: " << endl;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    // function to find the vertex with minimum
    // distance value, from the set of vertices not yet included
    // in shortest path tree
    int minDistance(int dist[], bool visited[])
    {
        int min = 9999, min_index;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i], min_index = i;
            }
        }
        return min_index;
    }

    void printMindistances(int dist[],int source)
    {
        cout << endl;
        //cout << "Vertex \t\t Distance from Source" << endl;
        for (int i = 0; i < v; i++)
        {
            cout <<source<<" -> "<< i << " \t\t" << dist[i] << endl;
        }
    }

    void dijkstra()
    {
        int source;
        cout << "\nEnter source: ";
        cin >> source;
        // The output array.dist[i] will hold the
        // shortest
        // distance from source to i
        int dist[v];
        // visited[i] will be true if vertex i is
        // included in shortest
        // path tree or shortest distance from src to i is
        // finalized
        bool selected[v];

        // Initialize all distances as INFINITE and
        // visited[] as  false
        // Distance of source vertex from itself is always 0
        for (int i = 0; i < v; i++)
        {
            dist[i] = 9999;
            selected[i] = false;
        }
        dist[source] = 0;

        // Find shortest path for all vertices
        for (int i = 0; i < v; i++)
        {
            // Pick the minimum distance vertex from the set of
            // vertices not yet processed. nearest is always equal to
            // src in the first iteration.
            int nearest = minDistance(dist, selected);

            // Mark the picked vertex as processed
            selected[nearest] = true;

            // Update dist value of the adjacent vertices of the
            // picked vertex.
            for (int adj = 0; adj < v; adj++)
            {
                // Update dist[i] only if is not in visited,
                // there is an edge from nearest to adj vertex, and total
                // weight of path from src to  adj vertex through nearest is
                // smaller than current value of dist[adj]
                if (!selected[adj] && (arr[nearest][adj] != 0) && (dist[nearest] + arr[nearest][adj] < dist[adj]))
                {
                    dist[adj] = dist[nearest] + arr[nearest][adj];
                }
            }
        }
        cout << endl;
        printMindistances(dist,source);
    }

};

int main()
{
    Graph g;
    g.accept();
    g.display();
    cout << "Shortest distance from source using Dijkstra algorithm: ";
    g.dijkstra();
}
