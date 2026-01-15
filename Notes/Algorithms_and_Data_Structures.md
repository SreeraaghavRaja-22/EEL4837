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
- Programming Running Time
    - most algorithms transform input objects into output objects 
    - **running time** of an algorithm **increases** with **input size**
    - Generally difficult to measure average case 
    - Typically focus on worst-case analysis
        - good for hardware and games 
- **Worst Case for Any Search**: number doesn't exist
