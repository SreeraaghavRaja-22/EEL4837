#include <bits/stdc++.h>
#include "p2.h"


int main(void){
    Node a[4]; // avoid segmentation fault by having all the nodes default to 0; (if they're all pointing to nothing then it's bad)
    a->val = 5; 
    a->next = &a[1];

    a[1].val = 8;
    a[1].next = &a[2];

    a[2].val = 12; 
    a[2].next = &a[3];
    
    a[3].val = 20; 
    a[3].next = nullptr; // points to nothing (end of linked list)

    Node* head = a; 

    // target is a[2] 
    Node* target = &a[2]; 

    // print all the nodes before deleting Node C
    PrintNodes(head);

    // use delete node function
    DeleteNode(head, target);

    // Print the node values after removing Node C;
    PrintNodes(head);
    return 0; 
}

void DeleteNode(Node* head, Node* target){
    // set a temporary pointer of node type to head; 
    Node* temp;
    temp = head; 
    do{
        // traverse the linked list
        temp = temp -> next; 
        if(temp -> next == nullptr){
            return; 
        }
    }while(temp != target);

    // initialize prev and next nodes from target
    Node* next = target -> next; 
    Node* prev = (target-1);

    // target-1 -> next points to target -> next;
    // removes target node
    prev -> next = next; 
    return; 
}

void PrintNodes(Node* head){
    Node* temp;
    temp = head; 
    do{
        if(temp -> next == nullptr)
            std::cout << temp->val << std::endl;
        else
            std::cout << temp->val << ",";

        temp = temp -> next; 
    }while(temp != nullptr);
    
    return;
}