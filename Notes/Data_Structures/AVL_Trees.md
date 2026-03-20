# AVL Trees

## Binary Search Treees

- **Binary Search Tree (BST)**: a binary tree where each non-empty node R has the following properties:
  - every element of R's left substree contains data less than R's data 
  - every element of R's right substree contains data greater than R's data
  - R's left and right subtrees are also BSTs
- BSTs store their elements in sorted order, which is helpful for searching/sorting tasks

### BST Logistics

- All BST operations take O(d) time, where d is the depth of the tree
- the minimum d is d = [log_2(n)]
- the maximum d is d = n where n is the number of nodes
- The **best case running time of a BST** is O(log(n))
- The **worst case running time of a BST** is O(n)
  - This occurs when the tree is skewed, i.e., it is not balanced
    - **Unbalanced Degenerate Tree**: A BST that is not balanced

#### How do we Balance Search Trees

- Don't Balance: may end up with some nodes which are very deep
- Strict Balance: the tree must be balanced perfectly
- Pretty Good Balance: only allow a little out of balance
- Adjust on Access: self-adjusting
  - This is super expensive

## AVL Tree Basics

- **Adelson-Velsky Landis (AVL) Tree**: a height-balanced binary search tree
- **Balance Factor**: height(left subtree) - height(right subtree)
  - The balance factor of every node in an AVL tree must be -1, 0, or 1
  - Store current heights in each node

### Height of AVL Trees

- The height of an AVL tree is O(log(n))
- The proof is by induction
  - Base case: n = 1, height = 0 = log(1)
  - Inductive step: Assume that for all k < n, the height of an AVL tree with k nodes is O(log(k))

### Maintaining Balance in AVL Tree

- Assume the tree is balanced
- After each insertion, find the lowest node *k* that violates the balance condition
- Perform rotation to re-balance tree

### Single Roation Algorithm

- For Outside Imbalance
- RotateFromRight(n: reference node pointer){
  p: node pointer
  p := n.right
  n.right := p.left
  p.left := n
  // update heights of n and p
  n := p
}

### Internal Imbalance

- Imbalanced height in the middle of the tree
- For a 3 level tree, we need 2 rotations to fix it
- **Double rotation algorithm**:
  - DoubleRotateFromRight(n : reference node pointer){
    RotateFromRight(n.right);
    RotateFromLeft(n);
  }

### AVL Tree Insertion

```cpp

Insert(T : tree pointer, x : element) : {
  If T = null then
    T := new tree; T.data := x; height := 0;
    case 
      T.data = x : return; // Duplicate nodes not allowed
      T.data > x : Insert(T.left, x);
                   if((height(T.left) - height(T.right)) > 1){
                    if(T.left.data > x){  // Outside Case
                      T = RotateFromLeft(T);
                    }else{ // Inside Case
                      T = DoubleRotateFromLeft(T);
                    } 
                   }
      T.data < x : Insert(T.right, x);
                   if((height(T.right) - height(T.left)) > 1){
                    if(T.right.data < x){  // Outside Case
                      T = RotateFromRight(T);
                    }else{ // Inside Case
                      T = DoubleRotateFromRight(T);
                    } 
                   }
    endcase
    T.height := 1 + max(height(T.left), height(T.right));
    return;
  }
}
```

### AVL Tree Deletion

- Similar but more complex than insertion
- After deletion, we need to re-balance the tree
- Imbalance may propagate up the tree, so many rotations may be needed

### AVL Tree Pros and Cons

- **Pros**:
  - Search is O(log N) since AVL trees are **always balanced**
  - Insertion and deletions are also O(log N)
  - The height balancing adds no more than a constant factor to the speed of insertion
- **Cons**:
  - Difficult to program and debug; more space needed for balance factor
  - Asymptotically faster, but rebalancing costs time
  - Most large searches are done in database systems on disk and use other structures (e.g. B-Trees)
  - It's only OK to have O(N) for a single operation if the total run time for many consecutive operations is fast (SPLAY TREES)
