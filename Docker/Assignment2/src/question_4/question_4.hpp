#ifndef QUESTION_4_HPP
#define QUESTION_4_HPP

#include <iostream>

struct AVLNode {
    int value;
    int bf;
    int height;
    int counter;
    struct AVLNode* left;
    struct AVLNode* right;
};
AVLNode* createNode(int value);

// Function prototypes
AVLNode* Insert(AVLNode*& root, int insertValue);
AVLNode* Search(AVLNode* root, int searchValue);
AVLNode* deleteAVLNode(AVLNode*& root, int deleteValue);

void traversePreOrder(AVLNode* root);
void traverseInOrder(AVLNode* root);
void traversePostOrder(AVLNode* root);

AVLNode* InsertNodes(int array[], int size, AVLNode* root);

#endif