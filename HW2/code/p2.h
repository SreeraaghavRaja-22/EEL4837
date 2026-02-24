#ifndef P2_DEF_H
#define P2_DEF_H

struct Node{
    int val; 
    Node *next; 
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};


void DeleteNode(Node* head, Node* target);
void PrintNodes(Node* head);
double AverageDeleter(Node* head);


#endif /*P2_DEF_H*/