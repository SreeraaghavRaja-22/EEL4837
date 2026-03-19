# Dynamic Programming

## Dynamic Programming Basics

- **Definition**: general algorithm method to solve optimization problems by breaking them down into smaller, overlapping subproblems
- **Steps**:
  1. Set up a recurrance that relates a solution of a larger instance to solutions of smaller cases
  2. Solve the small subproblems first
  3. Record the solutions in a table
  4. Use the solutions to solve the original problem

## Backstory: Divide and Conquer

- Basically with take the smaller subproblems and combine them to solve the original problem
- Issue: the smaller problems all have different solutions, so the original solution is **inefficient**

## DP: Efficient Divide and Conquer

- Dynamic Programming imrpoves the **inefficient divide and conquer** algorithms
- **Inefficient**: the same recursive call is made over and over
  - Solve this by storing the solution in a table so we never have to **recompute**
- DP is useful when subproblems are **dependent** which means that subproblems *share* subproblems

## DP Example: Fibonacci Numbers

```cpp
// Inefficient (Recursion)
int fib(int n) {
  if (n <= 1) return n;
  return fib(n - 1) + fib(n - 2);
}

// Efficent (DP)
long fibonacci (int n){
    if (n == 1){
        return 1; 
    }

    // Initialize the "table"
    long last = 1; 
    long nextToLast = 0; 
    long answer = 1; 

    for (int i = 2; i <= n; ++i){
        answer = last + nextToLast; // combine subproblem solutions 
        nextToLast = last; // update subproblem solutions
        last = answer; 
    }

    return answer; 
}
```

## Sequential Viewpoint of Dynamic Programming

- **Problem**: compute a sequence of decisions with minimal cost
  - **Optimal Solution** minimizes the cost
  - E.g, which edges to take for a shortest path on a graph
- **Brute Force**: try all sequences of decisions
- **Greedy Approach**: use recent information **to make one decision at a time**
- **Dynamic Programming**: work out **optimal solutions to subproblems**
  - Ignore all **suboptimal solutions to subproblems**
  - Optimal solution is composed of optimal subsequences
    - Need to know how optimal sequence & costs are structured

## Matrix Chain Ordering Problem

- **Given**: a chain of matrices of different sizes
- **Expected Result**: a product of **fully parenthized matrices**
- **Goal**: find the most **efficient** way to multiply the matrices
  - Minimize number of scalar products for computing the product
- **Solution**:
    1. First do a **recursive characterization**: Ai...Aj = (Ai...Ak) x (Ak+1...Aj)
    2. For a decomposition at k, get a formula for the **cost of multiplication**: m[i, j] = m[i, k] + m[k+1, j] + (p[i-1] x p[k] x p[j])
    3. Compute the costs for all possible decompositions

```cpp
// Optimal Matrix Ordering Code

// p: column counts of matrices, except p[0] is the row count of the first matrix
int optMatrix (const vector<int> & p){
    int n = p.size() - 1; 
    // Initialize the table
    matrix<int> m; 
    for (int i = 1; i <= n; ++i)
        m[i][i] = 0; 
    for(int row = 1; row < n; ++row){
        for(int left = 1; left <= n; ++left){
            int right = left + row; 
            m[left][right] = INT_MAX; // same as infinity
            for(int k = left; k < right; ++k){
                int thisCost = m[left][k] + m[k+1][right] + p[left-1]*p[k]*p[right];
                if (thisCost < m[left][right])
                    m[left][right] = thisCost;
            }
        }
    }   
}
```

### Divide and Conquer vs Dynamic Programming

- **Divide and Conquer**:
  - Break problem into **independent** subproblems
  - Doesn't store solutions, so identical subproblems, so computations performed multiple times
  - Top-Down Algorithms: starts from initial instance and goes down to the smallest subinstances
- **Dynamic Programming**:
  - Break problem into **overlapping** subproblems
  - Stores solutions to subproblems, so identical subproblems are only computed once
  - Bottom-Up Algorithms: starts from the smallest subproblems and works up to the initial instance
