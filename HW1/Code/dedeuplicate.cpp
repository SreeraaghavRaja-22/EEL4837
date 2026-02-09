#include <bits/stdc++.h>

void BubbleSortOpt(int n, int a[]); 

void Swap(int &x, int &y);

int deduplicate(int nums[], int n);

void PrintArray(int a[], int n);



// int main(void){
//     int a[] = {9, 12, 2, 1, 4, 20, 0, -1, 20, 8, 7, 7, 199};
//     int n = sizeof(a) / sizeof(a[0]);
//     int size = deduplicate(a, n);
//     std::cout << size << std::endl;
//     return 0;
// }

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

    if(n <= 1){return;}

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
    // treat this like a fifo 
        BubbleSortOpt(n, nums);
    // PrintArray(nums, n);
    int read_inx; 
    int write_inx = 1; // first unique element 
    int pos_val_inx;

    // return the array size if it's less than or equal to 1 element
    if(n <= 1){return n;}

    for(read_inx = 0; read_inx < n; read_inx++){
        if(nums[read_inx] > 0){
            pos_val_inx = read_inx;
            break;
        }
    }

    for(read_inx = pos_val_inx; read_inx < n; read_inx++){
        nums[read_inx - pos_val_inx] = nums[read_inx];
    }
    
    // update n value; 
    n -= pos_val_inx;

    for(read_inx = 1; read_inx < n; read_inx++){

        // compare the current index being read to the index of the first unique element
        if(nums[read_inx] != nums[write_inx - 1]){
            // std::cout << nums[write_inx] << " " << nums[read_inx] << std::endl;

            // replace the unique element with the current element
            nums[write_inx] = nums[read_inx];

            // every time this doesn't increment, the duplicate value gets replaced
            // key thing to note try checking for when something doesn't happen to optimize logic
            write_inx++;
        }
    }
    
    int arr_size = write_inx;

    // std::cout << "arr size: " << arr_size << '\n';
    // PrintArray(nums, arr_size);

    return arr_size;

    // tried to implement it this way and it works, but I wanted to optimize it
    // int initial_value = nums[0];
    // int num_duplicates;
    // int arr_size = n; 
    
    // // loop through array and check num of duplicate values
    // // while i is less than array size  
    // for(int i = 0; i < arr_size; i++){

    //     initial_value = nums[i];
    //     num_duplicates = 0;

    //     for(int j = i; j < arr_size; j++){
    //         if(initial_value == nums[j]){
    //             num_duplicates++;
    //             std::cout << "Initial Value\n";
    //             std::cout << "iteration " << i << " , Output: " << nums[j] << '\n';
    //         }
    //     }
        
    //     int initial_loop_index;
    //     // if there are duplicates, shift the array down
    //     if(num_duplicates > 1){
    //         if ((i + num_duplicates) > arr_size) {
    //             initial_loop_index = arr_size;
    //             std::cout << initial_loop_index << "bruh\n";
    //         }
    //         else {initial_loop_index = i + num_duplicates;}

    //         for(int j = initial_loop_index; j < arr_size; j++){
    //             nums[j - (num_duplicates - 1)] = nums[j];   
    //             std::cout << "Previous Value: " << nums[j - (num_duplicates - 1)] << ", Next Value: " << nums[j] << std::endl;
    //         }
    //         std::cout << std::endl;
    //         PrintArray(nums, arr_size);

    //         arr_size -= (num_duplicates - 1);

    //     }
    // }

    // std::cout << "Final Array Size: " <<arr_size << std::endl;
    // return arr_size; 
}