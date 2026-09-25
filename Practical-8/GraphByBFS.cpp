#include <iostream>

using namespace std;

struct Node {
    int dest;
    Node* next;
};

class Graph {
    int V;
    Node** adjList;

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

    void bfs(int startVertex) {
        bool* visited = new bool[V]();
        int* queue = new int[V];
        int front = 0;
        int rear = 0;

        visited[startVertex] = true;
        queue[rear++] = startVertex;

        cout << "BFS Traversal starting from vertex " << startVertex << ": ";

        while (front < rear) {
            int currVertex = queue[front++];
            cout << currVertex << " ";

            Node* temp = adjList[currVertex];
            while (temp != nullptr) {
                int neighbor = temp->dest;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue[rear++] = neighbor;
                }
                temp = temp->next;
            }
        }
        cout << endl;

        delete[] visited;
        delete[] queue;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    g.bfs(0);

    return 0;
}
