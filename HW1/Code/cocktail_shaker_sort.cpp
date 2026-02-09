#include <bits/stdc++.h>

void BubbleSortOpt(int n, int a[]); 

void Swap(int &x, int &y);

void PrintArray(int a[], int n);


// int main(void){
//     int a[] = {};
//     int n = sizeof(a) / sizeof(a[0]);
//     BubbleSortOpt(n, a);
//     return 0;
// }

void Swap(int &x, int &y){
    int tmp = x; 
    x = y; 
    y = tmp; 
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

void BubbleSortOpt(int n, int a[]){
    bool dir_flag = 0; 
    int num_swaps; 
    if(n <= 1){
        if(n == 1)
            PrintArray(a, n);
        else    
            std::cout << std::endl;
        return;
    }

    for(int i = 0; i < n; i++){
        num_swaps = 0; 
        if(dir_flag){
            for(int j = 0; j < n - 1; j++){
                if(a[j + 1] < a[j]){
                    Swap(a[j], a[j+1]);
                    num_swaps += 1;
                }
            }

            if(num_swaps == 0) {break;}
        }
        else{
            for(int j = n - 1; j > 0; j--){
                if(a[j] < a[j-1]){
                    Swap(a[j], a[j-1]);
                    num_swaps += 1;
                }
            }

            if(num_swaps == 0) {break;}
        }

        // change flag direction
        dir_flag ^= 1;
        
    }
    // print sorted array
    PrintArray(a, n);
}