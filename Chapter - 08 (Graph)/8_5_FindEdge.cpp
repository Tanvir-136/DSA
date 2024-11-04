#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Graph {
    unordered_map<int, vector<int>> adjList; 
};

void addEdge(Graph &graph, int nodeA, int nodeB) {
    graph.adjList[nodeA].push_back(nodeB); 
    graph.adjList[nodeB].push_back(nodeA);
}

bool findNode(const Graph &graph, int node) {
    return graph.adjList.find(node) != graph.adjList.end();
}

bool findEdge(const Graph &graph, int nodeA, int nodeB) {
    if (!findNode(graph, nodeA) || !findNode(graph, nodeB)) {
        return false; 
    }
    for (int neighbor : graph.adjList.at(nodeA)) {
        if (neighbor == nodeB) {
            return true; 
        }
    }
    return false; 
}

int main() {
    Graph graph;
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    int nodeA = 1, nodeB = 3; 
    if (findEdge(graph, nodeA, nodeB)) {
        cout << "Edge (" << nodeA << ", " << nodeB << ") exists in the graph.\n";
    } else {
        cout << "Edge (" << nodeA << ", " << nodeB << ") does not exist in the graph.\n";
    }
    return 0;
}