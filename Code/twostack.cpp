#include <iostream>
#include <stdlib.h>


class two_stacks {

    int *arr; 
    int size; 
    int top1, top2; 

    public: 
        two_stacks(int n){
            size = n; 
            arr = new int[n];
            top1 = n / 2 + 1; // start at the middle indices for the top1 and top2 
            top2 = n / 2; 
        } 

        void push1(int x){
            if(top1 < size){
                arr[top1++] = x;
            }
            else{
                std::cout << "stack overflow error in stack 1\n";
            }
        }

        void push2(int x){
            if(top2 >= 0){
                arr[--top2] = x;
            }
            else{
                std::cout << "stack overflow error in stack 2\n";
            }
        }

        int pop1(){
            if(top1 > size/2){
                return arr[--top1];
            }
            else{
                return -1;
            }
        }

        int pop2(){
            if(top2 < size / 2){
                return arr[top2++];
            }
            else{
                return -1;
            }
        }
};