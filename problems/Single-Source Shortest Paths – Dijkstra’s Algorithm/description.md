Given a source vertex s from a set of vertices V in a weighted digraph where all its edge weights w(u, v) are non-negative, find the shortest path weights d(s, v) from source s for all vertices v present in the graph.

For example,

Vertex	Minimum Cost	Route
A —> B	4	A —> E —> B
A —> C	6	A —> E —> B —> C
A —> D	5	A —> E —> D
A —> E	3	A —> E
Dijkstra’s Algorithm 

Practice this problem

We know that the Breadth–first search (BFS) can be used to find the shortest path in an unweighted graph or even in a weighted graph having the same cost of all its edges. But if edges in the graph are weighted with different costs, then BFS generalizes to uniform-cost search. Instead of expanding nodes to their depth from the root, uniform-cost search expands the nodes in order of their cost from the root. A variant of this algorithm is known as Dijkstra’s algorithm.

 Dijkstra’s Algorithm is an algorithm for finding the shortest paths between nodes in a graph. For a given source node in the graph, the algorithm finds the shortest path between that node and every other node. It can also be used for finding the shortest paths from a single node to a single destination node by stopping the algorithm once the fastest route to the destination node has been determined.

Dijkstra’s Algorithm is based on the principle of relaxation, in which more accurate values gradually replace an approximation to the correct distance until the shortest distance is reached. The approximate distance to each vertex is always an overestimate of the true distance and is replaced by the minimum of its old value with the length of a newly found path. It uses a priority queue to greedily select the closest vertex that has not yet been processed and performs this relaxation process on all of its outgoing edges.

 Following is pseudocode for Dijkstra’s Algorithm as per Wikipedia.

function Dijkstra(Graph, source)     dist[source] = 0    // Initialization    create vertex set Q     for each vertex v in Graph    {        if v != source        {            dist[v] = INFINITY        // Unknown distance from source to v            prev[v] = UNDEFINED       // Predecessor of v        }        Q.add_with_priority(v, dist[v])    }    while Q is not empty    {        u = Q.extract_min()           // Remove minimum        for each neighbor v of u that is still in Q        {            alt = dist[u] + length(u, v)            if alt < dist[v]            {                dist[v] = alt                prev[v] = u                Q.decrease_priority(v, alt)            }        }    }    return dist[], prev[]
For instance, consider the following graph. We will start with vertex A, So vertex A has a distance 0, and the remaining vertices have an undefined (infinite) distance from the source. Let S be the set of vertices whose shortest path distances from the source are already calculated.

Dijkstra’s Algorithm: Step 1

Initially, S contains the source vertex. S = {A}.

We start from source vertex A and start relaxing A's neighbors. Since vertex B can be reached from a direct edge from vertex A, update its distance to 10 (weight of edge A–B). Similarly, we can reach vertex E through a direct edge from A, so we update its distance from INFINITY to 3.

Dijkstra’s Algorithm: Step 2

After processing all outgoing edges of A, we next consider a vertex having minimum distance. B has a distance of 10, E has distance 3, and all remaining vertices have distance INFINITY. So, we choose E and push it into set S. Now our set becomes S = {A, E}. Next, we relax with E's neighbors. E has 2 neighbors B and C. We have already found one route to vertex B through vertex A having cost 10. But if we visit a vertex B through vertex E, we are getting an even cheaper route, i.e., (cost of edge A–E + cost of edge E–B) = 3 + 1 = 4 < 10 (cost of edge A–B).

 Dijkstra’s Algorithm: Step 3

We repeat the process till we have processed all the vertices, i.e., Set S becomes full.

Dijkstra’s Algorithm: Step 4

Dijkstra’s Algorithm: Step 5

Dijkstra’s Algorithm: Step 6

Dijkstra’s Algorithm: Step 7

