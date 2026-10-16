#include <iostream>

using namespace std;

// Define a maximum limit for the number of vertices
#define MAX_V 100
// Use a large constant literal to represent infinity (replaces INT_MAX)
#define INF 999999

// Function to find the vertex with the minimum key value
// from the set of vertices not yet included in the MST
int findMinVertex(int V, int key[], bool inMST[]) {
    int minWeight = INF;
    int minVertex = -1;

    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < minWeight) {
            minWeight = key[v];
            minVertex = v;
        }
    }
    return minVertex;
}

// Function to find and print the MST using Prim's algorithm
void primMST(int V, int graph[MAX_V][MAX_V]) {
    int parent[MAX_V]; // Array to store constructed MST
    int key[MAX_V];    // Values used to pick minimum weight edge in cut
    bool inMST[MAX_V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITY and inMST[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        inMST[i] = false;
        parent[i] = -1;
    }

    // Always include the first vertex in MST.
    // Make key 0 so that this vertex is picked first.
    key[0] = 0;

    int totalWeight = 0;

    // The MST will have V vertices
    for (int count = 0; count < V; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = findMinVertex(V, key, inMST);

        // If the graph is disconnected or node cannot be reached
        if (u == -1) break; 

        // Add the picked vertex to the MST Set
        inMST[u] = true;
        totalWeight += key[u];

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of m
            // inMST[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST edges and their weights
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
        }
    }
    cout << "\nTotal Weight of Minimum Spanning Tree: " << totalWeight << endl;
}

int main() {
    int V = 5; // Total vertices (0 to 4)

    // Initialize adjacency matrix with 0 (no edge)
    int graph[MAX_V][MAX_V] = {0};

    // Helper macro/lambda to quickly populate the symmetric matrix
    // mapping graph[u][v] and graph[v][u] for undirected paths
    graph[0][1] = 2; graph[1][0] = 2;
    graph[0][3] = 6; graph[3][0] = 6;
    graph[1][2] = 3; graph[2][1] = 3;
    graph[1][3] = 8; graph[3][1] = 8;
    graph[1][4] = 5; graph[4][1] = 5;
    graph[2][4] = 7; graph[4][2] = 7;
    graph[3][4] = 9; graph[4][3] = 9;

    primMST(V, graph);

    return 0;
}
