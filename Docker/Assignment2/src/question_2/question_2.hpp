#ifndef QUESTION_1_HPP
#define QUESTION_1_HPP

#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
};

// Function prototypes
Node* Insert(Node*& root, int insertValue);
Node* Search(Node* root, int searchValue);
Node* deleteNode(Node*& root, int deleteValue);

void traversePreOrder(Node* root);
void traverseInOrder(Node* root);
void traversePostOrder(Node* root);

Node* InsertNodes(int array[], int size, Node* root);

#endif