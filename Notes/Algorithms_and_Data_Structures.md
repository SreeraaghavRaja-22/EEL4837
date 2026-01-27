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
  - use Unix commands to get wall clock time, user time, system time, kernel time, etc.
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

## Why so many data structures??

- **Ideal Data Structure**: fast, clean, and memory efficient
  - Generates Tensions
    - time vs. space
    - peformance vs. elegance
    - generality vs. simplicity
    - one operation's performance vs. another
- Ex: Dictionary
  - Implementable with many different data structures
    - List
    - Array
    - Binary Search tree
    - AVL Tree
    - Splay Tree
    - Red-Black Tree
    - Hash Table

## Abstract Data Types

- Mathematical representation of a data structure

## Data Structures

### Stack

#### Operations

- create
- destroy
- push
- pop
- is_empty
- is_full
- **Stack Property**: LIFO (Last In First Out)

#### Implementing a Stack with an Array

- adds elements from left to right
- pointer to the index of the top element
  - variable keeps track of the index of the top element

#### Performance and Limitations

- **Performance**
  - Let *n* be the number of elements in the stack
  - The space used is O(n)
  - Each operation runs in time O(1)
- **Limitations**
  - The maximum size of the stack must be defined beforehand and cannot be changed
  - try to push a new element into a full stack causes an exception

#### Evaluating (infix) Expressions (Two-Stack Algorithm)

- (1 + ((2 + 3) \* (4 \*5 )))
- Evaluated using the stack
- **Two-Stack Algorithm**
  - **Value:** push onto the value stack
  - **Operator:** push onto the operator stack
  - **Left parenthesis:** ignore
  - **Right Parenthesis:** pop operator and two values
    - push the result of applying that operator to those values onto the operand stack
- Implement in C++

```cpp
    int main(){



        return 0;
    }
```

### Postfix Expressions

- Postfix notation is another way of writing arithmetic expressions
- In postfix notation, the operator is written after two operands
  - infix: 2 + 5
  - postfix: 2 5 +
  - infix: (3 + ((4+5)*2))
  - postfix: 3 4 5 + 2 * +
- Evaluated from left to right
  - Pushing operands onto a stack
  - Pop and execute operations
- Precedence Rules and Parentheses are never needed
- **Exercises:**
  - Convert a (fully parenthesized) infix expression to postfix
  - Evaluate a postfix expression

## Algorithms

### Sorting Algorithms

- **Basic Description:** order an array (permute elements of an array to order elements)
- **Comparison-Based Sorts:** uses only comparisons to sort (<, <=, ==, =>, >)
- **Common Sorting Algorithms**
  - Bubble Sort
  - Insertion Sort
  - Merge Sort
  - Quick Sort
  - Bogo Sort

#### Bogo Sort (Aleem Sort - let's go gambling sort)

- **Description:** sorts a list by randomly shuffling the values and checking to see if they are sorted (wth)
  - scan the list and see if it is sorted
  - if not sorted, reshuffle and check again
- This is not an algorithm because it does not complete in a **finite number of steps**
  - Unknown time complexity
  - May never terminate

#### Bubble Sort

- Compare neighboring elements
- Swap if out of order
- Time-Complexity: *O(n^2)*

```cpp
// n = length of array

for(i = 0; i < n -1; i++){
    for(j = 0; j < n - 1 - i; j++){
        if(a[j+1] < a[j]){
            tmp = a[j];  // compare neighbours
            a[j] = a[j + 1]; // swap a[j] and a[j + 1]
            a[j + 1] = tmp; 
        }
    }
}

```

- n + (n-1) + (n-2) + ... + 1 = n(n+1) / 2

##### Variations of Bubble Sort

- Alternate passes start -> end and end -> start

#### Insertion Sort

- keeps inserting a particular value until it is completely sorted
- after `n-1` iterations, the array is sorted
- time complexity is `O[n^2]`

```cpp
for(int i = 0; i < n; i++){
  next_val = a[i];
  // slide elements down to make room for Next value
  int j = i; 
  while(j > 0 && a[j-1] > next_val){
    a[j] = a[j-1];
  }
}


```

## C++ Templates

- there are templates for classes that are modifiable for different types (function overloading)

```cpp

template <typename T>
class Array{
  private: 
    T* ptr
    int size; 
  public: 
    Array(T arr[], int s);
    void print();
};

template <typename T>
Arraya<T>::Array(T arr[], int s){
  ptr = new T[s];
  size = s;
  for(int i = 0; i < size; i++){
    ptr[i] = arr[i];
  }
}

template <typename T>
void Array<T>::print() {
  for(int i = 0; i < size; i++){
    cout << " " << *(ptr + i);
    cout<<endl;
  }
}

// general call of template with type iint

int main(){
  int arr[5] = {1, 2, 3, 4, 5};
  Array<int> a(arr, 5);
  a.print();
}

```

### Variation of Templates

```cpp

#include <iostream>
using namespace std; 

template <class T, class U>
// template <class T, class U = char>
class A{
  T x;
  U y; 
  public: 
    A(){
      cout << "constructor called" <<endl;
    }
};

int main(){
  A<char, char> a; 
  A<int, double> b; // can't call this without having the two parameters in template
  // A<char> c;
  return 0;
}

```

## Relatives of Big-O

### Big-Omega

- what the heck

### Big-Theta

- what the heck
