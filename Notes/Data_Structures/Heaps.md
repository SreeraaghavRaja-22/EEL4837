# Heaps

## Heap Data Structure

- In short, a **heap** is a *binary tree* with the f ollowing properties
  - Balanced
  - Left-justified or Full
  - (Max) **Heap Property:** no node has a value greater than its parent
- Motivation: sorting and priority queues
  - **Want quick insertion and removal**

## Balanced Binary Trees

- Background:
  - **depth of a node** is its distance from the root
  - **depth of a tree** is the depth from the deepest node

### Left-Justified Binary trees

- A balanced binary tree of depth n

## The Heap Property

- A node has the (max) **heap property** if the value in the node is greater or equal than the values in its (immediate) children
- All leaf nodes automatically have the heap property
- A binary tree is a **heap** if all nodes have the heap property

## Building a Heap

- **siftUP**: take a larger child and switch it with the parent

### Constructing a Heap

- Base Case: a tree consisting of a single node is a heap
- Construct a heap by adding one node at a time
- Add the node at the right of the rightmost node
  - might destroy the heap property of added node's parent
  - siftUp the node until the heap property is restored
- **Sifting up does not require/propagate changes through most of the heap**
- **Heapified** != **Sorted**

### Removing the Root

- What happens if we discard the root (maximum value)?
- How to fix the binary tree so that it is balanced and left-justified?
  - Solution:
    - remove the rightmost leaft at teh deepest level and use it for the new root
    - siftDown the new root until the heap property is restored

### Sorting with Heaps

- If a binary tree is balanced and left-justified, it can be represented as an array
  - the first eleemnt is the root, the rest are stored in level order
- **Heapsort**
  
  ```cpp
    Heapify the array;
    while (the array isn't empty){
      swap the root with the last element;
      decrement the array size;
      reheap the new root;
    }
  ```

- **Complexity Analysis:**
  - **Heapify**, we insert array elements one-by-one
    - Adding an element take O(1)
    - Sifting up takes O(log n)
    - We reheap n times in the while loop
    - Total: O(n log n)
      - same as **merge sort** but doesn't take an extra array
