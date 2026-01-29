# Recursion

## Recursion Background

- **Definition:** something that calls itself
  - solve a problem by solving a smaller version of the same problem
  - Ex: Factorial function
    - Return happens in the opposite order of the call
      - This IS A STACK

## Factorial Function Example

```cpp
int factorial(int n){
    if(n=0){
        return 1;
    }
    else{
        return (n * Factorial(n-1));
    }
}
```

## Time-Complexity

- What is the time-complexity of a recursive function?
  - T(n) = c + T(n-1)
  - T(n-1) = c + T(n-2)
    - all the constants are the same because the code is always the same for a recursive function
  - The overall time-complexity of O(n)

## Reversing an Array

```cpp

void reverse(int arr[], int start, int end){
    int temp;

    if(start < end){
        // swap the array
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // recursive call
        reverse(arr, start + 1, end - 1);
    }

    return;
}
```

### Time-Complexity of Reverse

- O(n)

## Issues with Recursion

- Some functions may not have enough parameters for recursion, so we may have to add parameters to generate a proper recursive sequence

## Guidelines for Recursive Programs

- Determine the **size_factor**
- Determine the **base case(s)**
- Determine the **general case**
- Verify the **algorithm**
  - Three-Question Method

### Three-Question Method

- Base Case Question
  - nonrecursive way out of this function?
- Smaller-Caller Question
  - does each recursive call involve a smaller case of the original problem?
- General-Case Question
  - assuming that all recursive call(s) work correctly, does the whole function work correctly?

### Notes for Recursive Functions

- Don't think about recursive functions procedurally
- Think about the components of the function and it is much easier to write

### Pros/Cons of Recursion

- Pros: **shorter** and more **elegant solution** that is **good for branching problems**
- Cons: takes a lot of CPU time since calling a function takes so long

### Practice

- Insertion sort but recursively
- Recursive problem to search for an element x in an unsorted array A
- Recursively find the number of occurrences of an element e in array A
- Solve the Towers of Hanoi problem
