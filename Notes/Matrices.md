# Matrices

## A Separate Sparse Matrix Representation

- Standard Definition: `a[MAX_ROWS][MAX_COLS`
- can locate any element quickly by writing `a[i][j]`
- **Sparse matrix wastes space**
  - Must consider alternate forms of representation
  - A matrix where most of the elements are 0

## Matrix Algorithms

- Compute Transpose of Matrix A
- Compute sum of two matrices
- Compute product of two matrices
- Compute the determinant of matrix A
- Write a progam to get the inverse of a matrix A

### Sparse Matrix Algorithms

1. Compute the transpose of A
2. Compute sum C = A + B
3. Compute C = A x B
4. Compute the determinant of A
5. Compute inverse of `A^-1`

### Solving Linear Equations with Matrices

- **A x b = Y**
  - `A: Equation Matrix`
  - `b: Variable Vector`
  - `Y: Output Vector`
- **Methodology**
  - *Gaussian Elimination*
  - Turn a **linear equation** into an **augmented matrix** and it should work.
  - Get everything to **Reduced Row Echelon Form (RREF)**
    - *Back Substitution*: scale the row by a fraction to make the pivot 1
- **Three Rules for Gaussian Elimination**
  - Transposing equations doesn't change their solution (switching rows doesn't change the solution)
  - Scaling an equation doesn't change the solution (scaling any row of an augmented matrix doesn't change the solution)
  - If a set of numbers satisfies two equation, then it also satisfies the equation which is one plus a scalar multiple of the other

---

- **Example: Back Substitution Implementation**