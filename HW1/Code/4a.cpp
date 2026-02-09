#include <bits/stdc++.h>



void InsertElementEnd(int e, int a[], int k, int n);
void PrintArray(int a[], int n);


int main(void){

    int a[7] = {7, 3, 1, 4, 6, 8};
    int n = 6; 
    int k = 2;
    InsertElementEnd(0, a, k, n);
    PrintArray(a, n);
    return 0;
}

void InsertElementEnd(int e, int a[], int k, int n){
    // Base Case 
    // find the place where n <= k which means that we must put e
    // or find the place where previous a[n-1] value is less than e;
    if(a[n-1] <= e || n <= k){
        a[n] = e; 
        return;
    }

    // Normal Case
    // shift the element to the right and decrement the value of n
    a[n] = a[n - 1];

    // go to the smaller casea
    InsertElementEnd(e, a, k, n-1);
}

void PrintArray(int a[], int n){
    for(int i = 0; i < n; i++){
        if(i == n-1){
            std::cout << a[n-1] << std::endl;
        }
        else{
            std::cout << a[i] << " ";
        }
    }
}