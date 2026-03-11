#ifndef QUESTION_2_HPP
#define QUESTION_2_HPP

#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
};

// Function prototypes
Node* Insert(Node*& root, int insertValue);
Node* Search(Node* root, int searchValue);

void traversePreOrder(Node* root);
void traverseInOrder(Node* root);
void traversePostOrder(Node* root);

Node* findSuccessor(Node* currentPoint);
Node* findPredecessor(Node* currentPoint);

Node* deleteNode(Node*& root, int deleteValue);

Node* findSmallest(Node* currentPoint);
Node* findLargest(Node* currentPoint);

Node* InsertNodes(int array[], int size, Node* root);

#endif