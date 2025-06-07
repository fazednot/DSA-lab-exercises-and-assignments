Bipartite Graph
Given an undirected graph, check if it is bipartite or not. A bipartite graph (or bigraph) is a graph whose vertices can be divided into two disjoint sets U and V such that every edge connects a vertex in U to one in V.

The following graph is bipartite as we can divide it into two sets, U and V, with every edge having one endpoint in set U and the other in set V:

Bipartite graph

Practice this problem

It is possible to test whether a graph is bipartite or not using a Breadth–first search (BFS) algorithm. There are two ways to check for a bipartite graph:

1. A graph is a bipartite graph if and only if it is 2–colorable.

While doing BFS traversal, each node in the BFS tree is given its parent’s opposite color. If there exists an edge connecting the current vertex to a previously colored vertex with the same color, then we can safely conclude that the graph is not bipartite.

2. A graph is a bipartite graph if and only if it does not contain an odd cycle.

If a graph contains an odd cycle, we cannot divide the graph such that every adjacent vertex has a different color. To check if a given graph contains an odd-cycle or not, do a breadth–first search starting from an arbitrary vertex v. If in the BFS, we find an edge, both of whose endpoints are at the same level, then the graph is not Bipartite, and an odd-cycle is found. Here, the vertex level is its minimum distance from the starting vertex v. So, the odd-level vertices will form one set, and the even-level vertices will form another.