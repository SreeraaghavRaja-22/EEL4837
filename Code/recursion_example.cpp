    #include <bits/stdc++.h>

void insertion_sort(int A[], int i, int x){};

int main(void){

}

// A = sorted array
// i = index
// x = value you're trying to insert
void insertion_sort(int A[], int i, int x){
    // base case
    if(i < 0 || A[i] <= x){
        A[i + 1] = x; 
        return;
    }

    // otherwise, insert your value to the right 
    A[i + 1] = A[i];

    insertion_sort(A, i - 1, x);
}