#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold `n` elements of type `vector<int>`
        adjList.resize(n);
 
        // add edges to the directed graph
        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};
 
// A BFS Node
struct Node
{
    // stores current vertex number and the current depth of
    // BFS (how far away from the source current node is)
    int vertex, depth;
};
 
// Perform BFS on graph `graph` starting from vertex `v`
int findTotalPaths(Graph const &graph, int src, int dest, int m)
{
    // create a queue for doing BFS
    queue<Node> q;
 
    // enqueue source vertex
    q.push({src, 0});
 
    // stores number of paths from source to destination having exactly `m` edges
    int count = 0;
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node
        Node node = q.front();
        q.pop();
 
        int v = node.vertex;
        int depth = node.depth;
 
        // if the destination is reached and BFS depth is equal to `m`, update count
        if (v == dest && depth == m) {
            count++;
        }
 
        // don't consider nodes having a BFS depth more than `m`.
        // This check will result in optimized code and handle cycles
        // in the graph (otherwise, the loop will never break)
        if (depth > m) {
            break;
        }
 
        // do for every adjacent vertex `u` of `v`
        for (int u: graph.adjList[v])
        {
            // enqueue every vertex (discovered or undiscovered)
            q.push({u, depth + 1});
        }
    }
 
    // return number of paths from source to destination
    return count;
}
 
int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges =
    {
        {0, 6}, {0, 1}, {1, 6}, {1, 5}, {1, 2}, {2, 3}, {3, 4},
        {5, 2}, {5, 3}, {5, 4}, {6, 5}, {7, 6}, {7, 1}
    };
 
    // total number of nodes in the graph
    int n = 8;
 
    // build a graph from the given edges
    Graph graph(edges, n);
 
    int src = 0, dest = 3, m = 4;
 
    // Do modified BFS traversal from the source vertex src
    cout << findTotalPaths(graph, src, dest, m);
 
    return 0;
}// Outputs 3