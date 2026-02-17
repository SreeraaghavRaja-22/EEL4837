# Pointers

## Pointer Arithmetic

- Pointers support basic arithmetic operations: addition, subtraction, increment, decrement
- When we add 1 to a pointer, it points to the next memory location (increments by the size of the data type it points to)

## Constant Pointers

- pointer can be a **constant** whose value (address) cannot be changed
- C++ treats the name of an array as **constant pointer** which contains address of the first location of array (base address)
- You can declare another pointer and set it equal to the constant pointer to be able to configure the base address to print out contents of an array

## Pointers and Strings

- A **C-Style String** is just an array of characters ending in '\0';

## Array of Pointers

- An array of pointers is an **array of arrays**
  - Can use them to store strings

## Passing Veriables into a Function

- **Call-by-Value**:
  - Copy of the variable is passed to the function
- **Call-by-Pointer**:
  - Address of the variable is passed to the function
  - will always have to dereference the pointer to access the value
- **Call-by-Reference**:
  - Alias of the variable is passed to the function

## C++ Memory Map

- A C++ program's memory is divided into 4 parts:
  - Program Code: it holds the compiled program that is ready for execution
  - Global Variables: they remain in memory for the duration of the program (like PC)
  - Stack: **static memory**
    - holds return addresses of function calls
    - arguments passed into the functions
    - local variables for functions
  - Heap: **dynamic memory**
    - **free memory**

### New and Delete Operators

- C++ allocates memory from the "free store"/"heap"/"pool" during **runtime**
  - **new** operator is used to allocate memory
  - **delete** operator is used to deallocate memory
  - The pointer is in the stack, but the memory is in the heap

### Dynamic Arrays

- Systems stop working when there is no memory left in the heap
  - Memory leak
  - Rebooting the system clears the heap, so everything starts working again

### Pointers and Structs

- Pointers can be used to access the members of a struct

### Pointers and Objects

- Pointers can be used to access elements in a class / object

### Self-Referential Structures

- structure which contains an element that points/refers to the structure itself

```cpp
struct students{
    int rollno;
    char name[20];
    students* nextStudent;
};
```

### Memory Leaks

- occurs when memory is allocated but never deallocated
