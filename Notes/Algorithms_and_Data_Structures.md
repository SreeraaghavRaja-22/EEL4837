# Algorithms and Data Structures 

## Background 

- **Algorithm**: procedure for solving a problem in a finite amount of time 
    - Ex: finding someone's name in a phone book
- **Data Structure**: a way that data is organized 
    - Ex: array, list, list of lists, tree, table, etc...

```cpp
    #include <iostream>

    int main(){
        std::cout << "Hello World!" << std::endl; 
        return 0;
    }
```

## Array Data Structure 

- **One-Dimensional Array**: data structure consisting of a collection of *elements* each identified by at least one *array index* or *key*
    - Keys are **contiguous sequence of numbers*
    - Stored on the **stack** that's why sequence of memory locations

```cpp 
    create_array(n); // creates an array of size n (conceptual)
    a[i] = x;        // assigns the value of x at index i
    x = a[i];        // reads the value of a[i] to x
```

## Algorithm Example: Linear Search 

- loop through each value of the array and loop through each index and compare to the value you want
    - **break** if it matches

```cpp
    int l_search(int arr[], int n, int x){
        int i; 
        for (i = 0; i < n; i++){
            if (arr[i] == x){return i;}
        }
        return -1;
    }

    void main(){
        int arr[] = {3, 4, 1, 7, 5}; 
        int n = 5; 
        int x = 4; 
        int index = l_search(arr, n, x);
        if(index == -1){
            cout << "Element is not present in the array\n";
        }
        else{
            cout << "Element is present in array at index: " << i << '\n';
        }
    }
```


## Searching a Sorted Array 

- **Binary Search Algorithm**: check the middle first and then go from there based on if the value is higher or lower than the middle 
    - Binary Search isn't always more efficient than Linear Search (like searching for 1), but usually more efficient

```cpp
    int binary_search(int arr[], int left, int right, int x){
        while (left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] == x) return mid; 
            else if(arr[mid] < x) left = mid + 1; // look at right half by increasing the left to be right after middle (mid + 1)
            else right = mid - 1;                 // look at left half by decreasing the right to be right before middle (mid - 1)
        }
        return -1; 
    }
```


## Time Complexity and Big-O Notation

- First Algorithm Ever: Euclid's Algorithm to get the GCD of 2 numbers
- **Programming Running Time**
    - most algorithms transform input objects into output objects 
    - **running time** of an algorithm **increases** with **input size**
    - Generally difficult to measure average case 
    - Typically focus on worst-case analysis
        - good for hardware and games 
- **Worst Case for Any Search**: number doesn't exist

### Measuring Program Running Time 

- run the program with inputs of varying size 
- "accurately measure the runnning time"
    - use Unix commands to get wall clock time, user time, system time, kernel time, etc.)
        - can just search this up when needed 

### Pseudocode example
```cpp
   Algorithm arrayMax(A, n)
   Input array A of n integers
   Output maximum element of A

   currentMax <- A[0]
   for i <-- 1 to n - 1 do 
    if A[i] > currentMax then 
    currentMax <- A[i]

    return currentMax
```

### Primitive Operations

- Basic Computations performed by algorithm
- Identifiable in pseudocode 
- Dependent on programming language
- **Assumed to take constant time to compute**
- Ex: 
    - Evaluating an expression
    - Assigning a variable 
    - Indexing into an Array 
    - Calling a method 
    - Returning from a method

### Definition of Big-O Notation 

- f(n) = O(g(n)) means there are positive constants c and n_0, such that 0 <= f(n) <= cg(n) for all n >= n_0. The values of c and n_0 must be fixed for the function f and must not depend on n.
- Subtlety of having T(n): as n grows, it must be bounded by T(n)
- 2n + 10 is O(n)
    - 2n + 10 <= cn, solve for c and n_0 (base case)
    - c = 3, n_0 = 10

### Rules of Big-O

- If f(n) is a polynomial of degree d, then f(n) is O(n^d), i.e.,
    1. Drop lower-order terms 
    2. Drop constant factors
- Use smallest possible class of functions 
    - Say "2n is O(n)" instead of "2n is O(n^2)"
- use the simplest expression of the class 
    - Say "3n + 5 is O(n)" instead of "3n + 5 is O(3n)"

### Big O and Growth Rates

- Big-O gives the upper bound on the growth rate of the function 
- Helps us rank functions according to growth rate 
- log(n) < n < nlog(n) < n^2 < n^3 < 2^n

### Asymptotic Analysis 

- asymptotic analysis of an algorithm determines the running time in Big-O Notation
- Analysis gets the **smallest, most minimal** function g(n) such that T(n) = O(g(n))
- We get the worst case number of primitive operations and put that into Big-O notation
    - this becomes our max running time

### Linear Search Time Complexity

- time complexity is order O(n)
- for any loop the running time is the n

### Binary Search Time Complexity

- time complexity is O(log_2(n))
    - Why?
        - Number of array indices considered is halved in each iteration
            - After k iterations, the number of indices considered will be n/2^k
            - Algorithm stops when indices run out: n/2^k <= 1
            - So we choose the the smallest k such that n/2^k = 1
                - n = 2^k
                - k = O(log(n))