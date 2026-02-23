#include <bits/stdc++.h>

int main(void){
    /*------------------- PROBLEM 1 -------------------*/
    /*int arr[5] = {2, 4, 6, 8, 10};
    int* p = arr + 1; 
    int* q = arr + 3; 

    *(p + 1) += *q; 
    q = p - 1; 
    *p = *q + *(p + 2);

    printf("%d, %d, %d, %d, %d\n%d, %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], *p, *q);

    std::cout << arr[0] << "," << arr[1] << "," << arr[2] << "," << arr[3] << "," << arr[4] << std::endl;

    std::cout << *p << "," << *q << '\n'; */
    /*------------------- PROBLEM 1 -------------------*/


    /*------------------- PROBLEM 2 -------------------*/
    // int arr[3] = {1, 3, 5};
    // int* p = arr; 
    // int* q = arr + 2; 

    // *(p + 2) = *p + *q; 
    // p++;
    // *q = *p + 4; 

    // int* r; 
    // r = p + 2; 

    // std::cout << arr[0] << "," << arr[1] << "," << arr[2] << std::endl;
    // std::cout << *p << "," << *q << std::endl;
    // std::cout << *r << std::endl; 

    /*------------------- PROBLEM 2 -------------------*/

    /*------------------- PROBLEM 3 -------------------*/
    int a = 2, b = 5; 
    int* p = &a; 
    int* q = &b; 

    while (*p < 10){
        int* temp = p;
        p = q; 
        q = temp; 
        (*q)++;
    }

    std::cout << a << "," << b << std::endl;

    /*------------------- PROBLEM 3 -------------------*/


    return 0;
}