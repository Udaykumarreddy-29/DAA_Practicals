#include <iostream>

using namespace std;

// Define maximum limits for vertices and edges
#define MAX_V 100
#define MAX_E 200

// Structure to represent a weighted edge
struct Edge {
    int src, dest, weight;
};

// --- DISJOINT SET UNION (DSU) FUNCTIONS FOR CYCLE DETECTION ---
int parent[MAX_V];
int ranks[MAX_V];

// Initialize DSU sets where each element is its own parent
void initDSU(int V) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

// Find the representative root of a set (with path compression)
int findSet(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]); // Path compression
}

// Union two sets by rank to prevent cycles
void unionSets(int u, int v) {
    int rootU = findSet(u);
    int rootV = findSet(v);

    if (rootU != rootV) {
        if (ranks[rootU] < ranks[rootV]) {
            parent[rootU] = rootV;
        } else if (ranks[rootU] > ranks[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            ranks[rootU]++;
        }
    }
}

// --- BUBBLE SORT FOR RAW ARRAYS ---
// Sorts the edges array in ascending order based on edge weight
void sortEdges(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                // Swap edges
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// --- KRUSKAL'S ALGORITHM ---
void kruskalMST(int V, int E, Edge edges[]) {
    // Array to store the final edges of the MST
    Edge mst[MAX_V]; 
    int mstEdgeCount = 0;
    int totalWeight = 0;

    // Step 1: Sort all edges by ascending weight
    sortEdges(edges, E);

    // Step 2: Initialize DSU tracking arrays
    initDSU(V);

    // Step 3: Iterate through sorted edges
    for (int i = 0; i < E; i++) {
        // If we already collected V-1 edges, the MST is complete
        if (mstEdgeCount == V - 1) break;

        Edge nextEdge = edges[i];
        int uRoot = findSet(nextEdge.src);
        int vRoot = findSet(nextEdge.dest);

        // If including this edge does not cause a cycle, add it
        if (uRoot != vRoot) {
            mst[mstEdgeCount++] = nextEdge;
            totalWeight += nextEdge.weight;
            unionSets(uRoot, vRoot);
        }
    }

    // Print the constructed MST edges and their weights
    cout << "\nEdges in the Minimum Spanning Tree:\n";
    cout << "Edge \tWeight\n";
    for (int i = 0; i < mstEdgeCount; i++) {
        cout << mst[i].src << " - " << mst[i].dest << " \t" << mst[i].weight << "\n";
    }
    cout << "\nTotal Weight of Minimum Spanning Tree: " << totalWeight << endl;
}

int main() {
    int V = 5; // Total vertices (0 to 4)
    int E = 7; // Total edges

    // Static array to store all graph edges
    Edge edges[MAX_E];

    // Populating the edge database manually
    edges[0] = {0, 1, 2};
    edges[1] = {0, 3, 6};
    edges[2] = {1, 2, 3};
    edges[3] = {1, 3, 8};
    edges[4] = {1, 4, 5};
    edges[5] = {2, 4, 7};
    edges[6] = {3, 4, 9};

    kruskalMST(V, E, edges);

    return 0;
}
