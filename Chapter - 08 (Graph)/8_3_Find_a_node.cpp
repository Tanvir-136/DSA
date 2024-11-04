#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int vertex;
    Node* next;
    Node(int v) : vertex(v), next(nullptr) {}
};
class Graph {
    int numVertices;           
    vector<Node*> adjList;     

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices, nullptr); 
    }

    void addEdge(int src, int dest) {
        Node* newNode = new Node(dest);
        newNode->next = adjList[src];
        adjList[src] = newNode;
        newNode = new Node(src);
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }
    Node* find(int start, int item) {
        Node* ptr = adjList[start];
        while (ptr != nullptr) {
            if (ptr->vertex == item) {
                return ptr;  
            }
            ptr = ptr->next;  
        }
        return nullptr;  
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ":";
            Node* temp = adjList[i];
            while (temp) {
                cout << " -> " << temp->vertex;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;
    Graph graph(vertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Graph adjacency list:\n";
    graph.printGraph();

    int start = 1, item = 3;
    Node* result = graph.find(start, item);
    if (result) {
        cout << "\nEdge from vertex " << start << " to vertex " << item << " found at location: " << result << endl;
    } else {
        cout << "\nEdge from vertex " << start << " to vertex " << item << " not found.\n";
    }
    return 0;
}