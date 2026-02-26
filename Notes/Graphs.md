# Graphs

## What is a Graph?

- A graph G = (V, E) is composed by
  - a set of Vertices (V)
  - a set of Edges (E) (a subset of V x V) connecting the vertices
    - An edge e = (u, v) is a pair of vertices

## Types of Graphs

- **Undirected Graph:** an edge (u, v) is the same as (v, u)
- **Directed Graph:** an edge (u, v) is not the same as (v, u)
- **Weighted Graph:** an edge has a weight associated with it
- **Unweighted Graph:** an edge has no weight associated with it

## Graph Applications

- Circuits
- Social Networks
- Process flow charts
- Tasks in a project
- Any sort of relationships

## Graph Terminology

- A vertex v is **adjacent** to vertex u iff (u,v) is an edge
- The **degree** of a vertex is the number of adjacent vertices
- A **path** is a sequence of vertices v_1, v_2, ..., v_k such that (v_i, v_{i+1}) is an edge for all 1 <= i < k
- A **simple path** is a path where all vertices are distinct
- A **cycle** is a path where the first and last vertices are the same
- A **connected graph** is a graph where any two vertices are connected by some path

## Representation: Adjacency Matrix

- A matrix where the entry (i, j) is 1 if there is an edge between vertex i and vertex j, and 0 otherwise

### Deficiencies of Adjacency Matrix

- Sparse graphs: waste space with a lot of 0s
  - Space Complexity: O(V^2)
- If number of nodes changes, the matrix representation is too inflexible (needs to be resized)

### Solution to Deficiencies: Adjacency List

- The **adjacency list** of a vertex v: holds verticies adjacent to v
- The graph is represented by adjacency lists of all its vertices
- Space required for adjacency list: O(V + E)
- Space required for adjacency matrix: O(V^2)

## Traversing a Graph

- Given a graph G = (V, E), write an algorithm to **traverse each node** in G

### Breadth-First Search (BFS)

- Create a queue Q
- Mark initial node v as visited and enqueue v in Q
- While Q is not empty:
  - Dequeue vertex u from Q
  - For each unvisited neighbor of n of u:
    - Mark n as visited
    - enqueue n in Q
- Time Complexity: O(V + E)

### Depth-First Search (DFS)

- Create a stack S
- Mark initial node v as visited and push v in S
- While S is not empty:
  - Pop vertex u from S
  - For each unvisited neighbor of n of u:
    - Mark n as visited
    - push n in S
- Time Complexity: O(V + E)

## Directed Acyclic Graphs (DAGs)

- A directed graph with no cycles
- DAGs are used to indicate precendence among events (event x must happen beforee y)
- An example would be parallel code execution

### Topological Sort

- A **topological sort** is an *ordering* of DAG vertices such that , if there is a *path* from v1 to v2, v1 appears before v2 in the ordering
- **Brute Force**: repeatedly remove nodes with 0 incoming edges
- **Kahn's Algorithm**: BFS-style "take apart" the graph in order of its edges
  - Time-Complexity: O(V + E)
