# Trees

## What is a Tree?

- An abstract data structure that consists of
  - A collection of *nodes* related by a parent-child relation
- **Applications**
  - Organization charts
  - File systems
  - Programming environments
- **Basics**
  - A tree is defined *recursively*
  - A tree is a **collection of nodes**
    - A base case (root node)
    - A set of subtrees (children)
    - Depth of Node: defined by number of ancestors
    - Height of Tree: defined by maximum any node
    - **Path**: a sequence of nodes that goes from parent to child
    - **Length of Path**: number of edges in the path
    - **Leaf**: a node with no children
    - **Root**: the top-most node in the tree
    - **Parent**: a node that has children
    - **Child**: a node that has a parent
    - **Sibling**: nodes that have the same parent
    - **Edge**: a connection between two nodes
    - **Degree**: the number of children a node has
    - **Order**: the number of children a node can have
    - **Ancestor**: any node that is on the path from the root to the node
    - **Descendant**: any node that is on the path from the node to a leaf

## Binary Trees

- tree in which **no** node can have **more than 2 children**
- each node has an **element**
  - A pointer to a **left child**
  - A pointer to a **right child**
- **Question**
  - **What is the maximum number of leaves in a binary tree of height *h*?**
    - 2^(h-1), when h indexing starts at 1
    - 2^(h), when h indexing starts at 0
- **Minimum number of leaves in a binary tree of height *h*?**
  - 1 (if constructing a linked list)
- **Maximum number of nodes in a binary tree of height *h*?**
  - 2^(h) -1, when h indexing starts at 1
  - 2^(h+1) -1, when h indexing starts at 0
- **Minimum number of nodes in a binary tree of height *h*?**
  - h, when h indexing starts at 1
  - h+1, when h indexing starts at 0

### Tree Operations

- Algorithms to
  - compute height of the tree (aka depth)
  - compute number of nodes
- How can you implement an **arbitrary tree** using a **binary tree**?
  - Use a **linked list** to store the children of each node
  - Use a **pointer** to the parent of each node
  - Use a **pointer** to the leftmost child of each node
  - Use a **pointer** to the right sibling of each node
- How can you implement a binary tree with an array without pointer or linked lists?

### Application: Arithmetic Expression Tree

- A binary tree can store an arithmetic expression
  - Internal nodes: operators
  - Leaves: operands
- Given an expression tree, we can evaluate the expression
- Print the fully parenthesized expression

### Other Tree Exercises

- Given a binary tree, print the elements in **level order**
  - Use a queue
  - Enqueue the root
  - Dequeue the root and enqueue its children
  - Repeat until the queue is empty

### Tree Traversal

- To **traverse** the tree means to visit each node in a binary tree **exactly once**

### Binary Search Tree

- **Binary Search Trees (BST):** a binary tree where each node R has the following properties
  - Every element of R's left subtree contains data less than R
  - Every element of R's right subtree contains data greater than R
- BSTs store their elements in **sorted order** (good for searching / storing tasks)

#### Searching a Binary Tree

- Describe an algorithm for **searching** a binary search tree.
  - Try searching for the value of 31
  - Then searching for 6
- What is the **maximum number of nodes** you would visit to perform any search?
  - The height of the tree
- What is the general algorithm?

- What is the time complexity?
  - log(n) (bushy tree)
  - n (skinny tree)

#### Deletion Algorithm

- if a leaf, just delete it
- if it has one child, move the child to the node
- if two children, then
  - set the value to be in-order successor; then delete the in-order sucessor node (recursively)
