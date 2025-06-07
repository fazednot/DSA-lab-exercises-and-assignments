#include <iostream>
#include <vector>
using namespace std;

// Custom simple queue implementation using vector
class MyQueue {
private:
    vector<int> data;
    int frontIndex = 0;

public:
    void push(int value) {
        data.push_back(value);
    }

    void pop() {
        if (!empty()) {
            frontIndex++;
        }
    }

    int front() {
        return data[frontIndex];
    }

    bool empty() {
        return frontIndex >= data.size();
    }
};

// Data structure to store a graph edge
struct Edge {
    int src, dest;
};

// A class to represent a graph object
class Graph {
public:
    vector<vector<int>> adjList;
    int n;

    Graph(vector<Edge> const &edges, int n) {
        this->n = n;
        adjList.resize(n);

        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

// Perform BFS on the graph starting from vertex `v`
bool isBipartite(Graph const &graph) {
    int n = graph.n;
    vector<bool> discovered(n, false);
    vector<int> level(n, -1);

    for (int start = 0; start < n; ++start) {
        if (!discovered[start]) {
            MyQueue q;
            discovered[start] = true;
            level[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int v = q.front();
                q.pop();

                for (int u : graph.adjList[v]) {
                    if (!discovered[u]) {
                        discovered[u] = true;
                        level[u] = level[v] + 1;
                        q.push(u);
                    } else if (level[u] == level[v]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    vector<Edge> edges = {
        {0, 1}, {1, 2}, {1, 7}, {2, 3},
        {3, 5}, {4, 6}, {4, 8}, {7, 8}
    };

    int n = 9;
    Graph graph(edges, n);

    if (isBipartite(graph)) {
        cout << "Graph is bipartite";
    } else {
        cout << "Graph is not bipartite";
    }

    return 0;
}
