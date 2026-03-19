# Djikstra's Algorithm

## Shortest Path in a Weighted Graph

- **Given**: a **weighted** directed graph
- Two nodes *s* and *t* in the graph
- **Goal**: find the **shortest path** from *s* to *t* and its **total weight**
  - Could implement for both **positive** and **negative** weights

### Shortest Path Problem Variants

- Single-source single-destination
- Single-source all-destinations
- All-sources single-destination
- All-pairs shortest paths (Floyd-Warshall)

## Reminder: BFS

- Create a queue Q
- Mark initial node V as visited and enqueue v in Q
- While Q is not empty:
  - Dequeue a vertex u from Q
  - For each unvisited neighbor n of u:
    - Mark n as visited
    - Enqueue n in Q
- Time-Complexity: O(V + E)
- **BFS generalizes level-order tree traversal**

## Dijkstra's Algorithm: Intuition

- **Problem**: single-source all-destinations **weighted** shortest path
- All edge weights have to be *non-negative*
- **Idea**: 
  - Build on the BFS for unweighted shrotest path
    - Keep track of nodes to visit in a queue Q
    - Keep track of which nodes have been visited in set S
    - Save the best path length to each node so far with dist[v]
    - Always visit the lowest-weight unvisited node
    next
      - Makes Q **priority queue** with *edge weight* as a priority
      - When we visit a node, we are *guaranteed to know* its shortest path length

### Dijkstra's Algorithm: Complexity Analysis

- **Unsorted Array**: O(V^2)
- **Binary Heap**: O((|V| + |E|) * log |V|)


### Cycles in Shorest Path Problems

- **Negative Cycles**: the shortest path is undefined 
- **Positive Cycles**: can be removed to produce a shorter path
- **Zero Cycles**: can be removed to produce a path of the same length
- *disregard cycles for our solutions*

### 