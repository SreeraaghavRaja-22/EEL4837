# Spanning Tree

## Spanning Tree Basics

- Suppose you have an **connected undirected graph**
  - **Connected**: every node is reachable from every other node
  - **Undirected**: edges have no direction
  - **Spanning Tree**: a subgraph is a connected subgraph in which there are no cycles

## Minimum Spanning Tree Problem

- Input: connected, undirected graph G with positive edge weights
- Output: a spanning tree of minimum weight
- Solution 1 - Brute Force: Try all spanning trees and find the minimum
- Utility: Network Design
  - Build a network link that minimizes length/difficulty/cost

### Properties of Spanning Trees

- **Let T be a spanning tree of connected graph G with V nodes**
    1. T has V-1 edges
    2. Removing any edge from T makes T disconnected
    3. Adding any edge to T creates exactly one cycle

### Cut Property

- **Definition**: A **cut** is a partition of the vertices of a graph into two disjoint sets
- **Crossing Edge** connectes a vertex in one set to a vertex in the other set.
- **Cut Property**: given any cut, the crossing edge of a minimum weight is an edge in some minimum spanning tree (MST)
- **Proof**: 
    1. Let (S, T) be a cut
    2. Let e = (u, v) be the minimum weight crossing edge
    3. If e is in some MST, we are done
    4. If e is not in any MST, then adding e to any MST creates a cycle

### Minimum Spanning Tree Algorithsm

Both are greedy algorithms!

#### Kruskal's Algorithm

- **Algorithm**: Sort edges by increasing edge weight and select the first |V|-1 edges that do not generate a cycle
- Time-Complexity: O(E log V)

#### Prim's Algorithm

- **Algorithm**: start growing a tree, greedily add the shortest edge we can to grow the tree

```cpp

// Prim's Algorithm Pseudocode
slowPrim( G = (V,E), starting at vertex s):
- let (s, u) be the lightest edge coming out of s
- MST = {(s, u)}
- verticesVisited = {s, u}
- while |verticesVisited| < |V|:
    - find the lightest edge (x, v) in E so that: 
        - x is in verticesVisited
        - v is not in verticesVisited
    - add (x, v) to MST
    - add v to verticesVisited
- return MST
```

- Time-Complexity: O(V^2) for a simple array
- Making the Code More Efficient: use a **priority queue**
  - Idea: use a priority queue / min-heap to store the unvisited edges
  - Use the adjacency list representation for easier edge traversal
  - Add all the vertices into the heap with infinite cost, draw any one & add to the MST
  - Repeat:
    - For adjacent vertices of the drawn still in the heap, update the min cost if needed
    - Draw the min-cost vertex from the heap and add to the MST
- Time-Complexity: O(E log V)

#### Kruskal vs. Prim

- Kruskal's algorithm 
  - is better for **sparse graphs** (few edges)
  - the tree we are making usually remains **disconnected**
  - grows a solution from the cheapest edge by adding the next cheapest edge to the existing tree/forest
- Prim's algorithm
  - is better for **dense graphs** (many edges)
  - the tree we are making usually remains **connected**
  - grows a solution from a random vertex by adding the next cheapest vertex to the existing tree