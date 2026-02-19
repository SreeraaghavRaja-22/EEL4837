# Linked Lists and Queues

## Linked Lists

### Singly Linked Lists

- is a list where each element is dynamically allocated and points to the location of the next element in the list
- Needs a **head** pointer

```cpp
    struct listItem{
        type payload; 
        listItem* next;
    }

    listItem *addAfter(listItem *p, listItem *q){
        q -> next = p -> next; // useful if you ever want to insert an element into the linked list, person B connects to person C (A connected to C at first)
        p -> next = q; // person A connects to person B
        return p; 
    }
```

- **Time-Complexity to add an element**: O(1) because it is a constant set of instructions
- **Time-Complexity to find an element**: O(n) because it is dependent on the size of the list
  - Usually slower than arrays because of the overhead of pointer manipulation
  - we cannot be more efficient than this (can't use binary search even if the array is sorted) because there is only one way to traverse the list

### Doubly Linked Lists

- is a list where each element is dynamically allocated and points to the location of the next element in the list
- Needs a **head** and **tail** pointer

```cpp
    struct listItem{
        type payload; 
        listItem* next;
        listItem* prev;
    }

    listItem *head, *tail;

    listItem *addAfter(listItem *p, listItem *q){
        q -> next = p -> next;
        p -> next = q; 
        return p; 
    }
```

## Queues

### Queue ADT

- **Queue Operations**
  - Enqueue: Add an element to the rear of the queue
  - Dequeue: Remove an element from the front of the queue
  - Create: Create a queue
  - Destroy: Destroy a queue
  - IsEmpty: Check if the queue is empty
  - IsFull: Check if the queue is full

- **Queue Property**: First In First Out (FIFO)
  - If *x* is enqueued before *y*, then *x* will be dequeued before *y* is dequeued

- **Key Question**: Can we implement a queue using a linked list / stack / doubly linked list?
  - Solution: keep 2 stacks
    - each stack is in reverse order of the other stack
    - when we enqueue, we push onto the first stack
    - when we dequeue, we pop from the second stack
    - if the second stack is empty, we pop from the first stack and push onto the second stack

- **Application of Queues**
  - Breadth-First Search (BFS)
  - Hold jobs for printer
  - Store packets on network routers
  - Hold memory "freelists"
  - Make waitlists fair (FIFO)

### How to Implement a Queue

- **Using an Array**
  - Issue: head an tail pointers will not line up at times
  - Solution: **Circular Array**
    - use an array of size N in a circular fashion
    - use mod to wrap around
    - Two variables keep track of the front and rear of the queue
      - front (f): index of the front element
      - rear (r): index immediately after the last element
      - array location r is kept empty
    - When is the array empty?
      - when f == r
    - When is the array full?
      - when (r + 1) % N == f
    - How do we calculate array size?
      - (N - f + r) % N

### Variants of a Stack and Queue

- **Dequeue (Double-Ended) Queue** is a data structure that allows insertiona and deletion of items at **both ends**
- **Priority Queue** supports the removeal of elements in **priority order**
