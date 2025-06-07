#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Structure to store a graph edge
struct Edge {
    int source, dest, weight;
};

// Structure for heap nodes
struct Node {
    int vertex, weight;
};

// Custom MinHeap class for Node
class MinHeap {
    vector<Node> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[i].weight < heap[(i - 1) / 2].weight) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int size = heap.size();
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left].weight < heap[smallest].weight) {
            smallest = left;
        }
        if (right < size && heap[right].weight < heap[smallest].weight) {
            smallest = right;
        }

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void push(Node node) {
        heap.push_back(node);
        heapifyUp(heap.size() - 1);
    }

    Node top() {
        return heap.front();
    }

    void pop() {
        if (heap.size() == 1) {
            heap.pop_back();
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    bool empty() const {
        return heap.empty();
    }
};

// Graph class using adjacency list
class Graph {
public:
    vector<vector<Edge>> adjList;

    Graph(vector<Edge> const &edges, int n) {
        adjList.resize(n);
        for (const Edge &edge : edges) {
            adjList[edge.source].push_back(edge);
        }
    }
};

// Recursive path printer
void printPath(const vector<int> &prev, int i, int source) {
    if (i < 0) return;
    if (i != source) {
        printPath(prev, prev[i], source);
        cout << ", ";
    }
    cout << i;
}

// Dijkstra's algorithm using custom MinHeap
void findShortestPaths(const Graph &graph, int source, int n) {
    MinHeap min_heap;
    min_heap.push({source, 0});

    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);
    vector<bool> done(n, false);

    dist[source] = 0;

    while (!min_heap.empty()) {
        Node node = min_heap.top();
        min_heap.pop();

        int u = node.vertex;
        if (done[u]) continue;
        done[u] = true;

        for (const Edge &edge : graph.adjList[u]) {
            int v = edge.dest;
            int weight = edge.weight;

            if (!done[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                min_heap.push({v, dist[v]});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != source && dist[i] != INT_MAX) {
            cout << "Path (" << source << " —> " << i << "): Minimum cost = "
                 << dist[i] << ", Route = [";
            printPath(prev, i, source);
            cout << "]\n";
        }
    }
}

int main() {
    vector<Edge> edges = {
        {0, 1, 10}, {0, 4, 3}, {1, 2, 2}, {1, 4, 4},
        {2, 3, 9}, {3, 2, 7}, {4, 1, 1}, {4, 2, 8}, {4, 3, 2}
    };

    int n = 5;
    Graph graph(edges, n);

    for (int source = 0; source < n; source++) {
        findShortestPaths(graph, source, n);
        cout << endl;
    }

    return 0;
}
// Output: Path (0 —> 1): Minimum cost = 4, Route = [0, 4, 1]Path (0 —> 2): Minimum cost = 6, Route = [0, 4, 1, 2]Path (0 —> 3): Minimum cost = 5, Route = [0, 4, 3]Path (0 —> 4): Minimum cost = 3, Route = [0, 4]Path (1 —> 2): Minimum cost = 2, Route = [1, 2]Path (1 —> 3): Minimum cost = 6, Route = [1, 4, 3]Path (1 —> 4): Minimum cost = 4, Route = [1, 4]Path (2 —> 3): Minimum cost = 9, Route = [2, 3]Path (3 —> 2): Minimum cost = 7, Route = [3, 2]Path (4 —> 1): Minimum cost = 1, Route = [4, 1]Path (4 —> 2): Minimum cost = 3, Route = [4, 1, 2]Path (4 —> 3): Minimum cost = 2, Route = [4, 3]