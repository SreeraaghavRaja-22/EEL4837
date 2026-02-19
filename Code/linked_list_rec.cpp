#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Recursive function to insert a node at the end
Node* insertRec(Node* node, int val) {
    if (node == nullptr) {
        return new Node(val);
    }
    node->next = insertRec(node->next, val);
    return node;
}

// Recursive function to print the list
void printRec(Node* node) {
    if (node == nullptr) {
        std::cout << "nullptr" << std::endl;
        return;
    }
    std::cout << node->data << " -> ";
    printRec(node->next);
}

// Recursive function to delete a node by value
Node* deleteRec(Node* node, int val) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->data == val) {
        Node* temp = node->next;
        delete node;
        return temp;
    }
    node->next = deleteRec(node->next, val);
    return node;
}

// Recursive function to search for a value
bool searchRec(Node* node, int val) {
    if (node == nullptr) {
        return false;
    }
    if (node->data == val) {
        return true;
    }
    return searchRec(node->next, val);
}

// Recursive function to free memory
void freeList(Node* node) {
    if (node == nullptr) {
        return;
    }
    freeList(node->next);
    delete node;
}

int main() {
    Node* head = nullptr;

    std::cout << "Inserting 10, 20, 30, 40..." << std::endl;
    head = insertRec(head, 10);
    head = insertRec(head, 20);
    head = insertRec(head, 30);
    head = insertRec(head, 40);

    std::cout << "List: ";
    printRec(head);

    std::cout << "Searching for 20: " << (searchRec(head, 20) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 50: " << (searchRec(head, 50) ? "Found" : "Not Found") << std::endl;

    std::cout << "Deleting 20..." << std::endl;
    head = deleteRec(head, 20);
    std::cout << "List: ";
    printRec(head);

    std::cout << "Deleting 10 (head)..." << std::endl;
    head = deleteRec(head, 10);
    std::cout << "List: ";
    printRec(head);

    std::cout << "Deleting 40 (tail)..." << std::endl;
    head = deleteRec(head, 40);
    std::cout << "List: ";
    printRec(head);

    // Clean up memory
    freeList(head);
    head = nullptr;

    return 0;
}
