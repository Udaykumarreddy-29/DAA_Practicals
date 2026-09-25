#include <iostream>

using namespace std;

struct Node {
    int dest;
    Node* next;
};

class Graph {
    int V;
    Node** adjList;

    void dfsUtil(int vertex, bool* visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        Node* temp = adjList[vertex];
        while (temp != nullptr) {
            int neighbor = temp->dest;
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
            temp = temp->next;
        }
    }

public:
    Graph(int vertices) {
        V = vertices;
        adjList = new Node*[V];
        for (int i = 0; i < V; ++i) {
            adjList[i] = nullptr;
        }
    }

    ~Graph() {
        for (int i = 0; i < V; ++i) {
            Node* temp = adjList[i];
            while (temp) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
        delete[] adjList;
    }

    void addEdge(int src, int dest) {
        Node* newNode = new Node{dest, adjList[src]};
        adjList[src] = newNode;

        newNode = new Node{src, adjList[dest]};
        adjList[dest] = newNode;
    }

    void dfs(int startVertex) {
        bool* visited = new bool[V]();
        
        cout << "DFS Traversal starting from vertex " << startVertex << ": ";
        dfsUtil(startVertex, visited);
        cout << endl;

        delete[] visited;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    g.dfs(0);

    return 0;
}
