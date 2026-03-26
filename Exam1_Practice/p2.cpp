#include <bits/stdc++.h>

typedef struct node {
    int data;
    node* right; 
    node* left;
} node;

int countSpecialNodes(node* root){
    if(root == nullptr){return 0;}

    int count_right = 0; int count_left = 0;
    
    node* root2 = root;

    // check all the values to the right
    if (root->right != nullptr && root->right->data > root->data){
        count_right = 1 + countSpecialNodes(root->right);
    }
    
    // check all the values to the left
    if(root->left != nullptr && root->left->data > root->data){
        count_left = 1 + countSpecialNodes(root->left);
    }

    return (count_right + count_left);
}