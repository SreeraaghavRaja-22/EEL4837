#include <bits/stdc++.h>

void BubbleSortOpt(int n, int a[]); 

void Swap(int &x, int &y);

int deduplicate(int nums[], int n);

void PrintArray(int a[], int n);



int main(void){
    int a[] = {9, 12, 2, 1, 4, 20, 20, 20, 8, 7, 7, 199};
    int n = sizeof(a) / sizeof(a[0]);
    BubbleSortOpt(n, a);
    int size = deduplicate(a, n);
    PrintArray(a, size);
    return 0;
}

void Swap(int &x, int &y){
    int tmp = x; 
    x = y; 
    y = tmp; 
}

void PrintArray(int a[], int n){
    for(int i = 0; i < n; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl; 
}

void BubbleSortOpt(int n, int a[]){
    bool dir_flag = 0; 
    int num_swaps; 

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
}

int deduplicate(int nums[], int n){ 

    // initial value = first value of array
    int initial_value = nums[0];
    int num_duplicates;
    int arr_size = n; 
    
    // loop through array and check num of duplicate values
    for(int i = 0; i < n; i++){

        initial_value = nums[i];
        num_duplicates = 0;

        for(int j = i; j < arr_size; j++){
            if(initial_value == nums[j]){
                num_duplicates++;
            }
        }

        // if there are duplicates, shift the array down
        if(num_duplicates > 0){
            for(int j = i + num_duplicates; j < arr_size; j++){
                nums[j - num_duplicates - 1] = nums[j];
            }

            arr_size = n - num_duplicates - 1;
        }
    }

    return arr_size;
}