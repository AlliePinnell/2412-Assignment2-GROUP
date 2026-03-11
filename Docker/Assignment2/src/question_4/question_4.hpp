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
int updateHeightBF(AVLNode* node);

void traversePreOrder(AVLNode* root);
void traverseInOrder(AVLNode* root);
void traversePostOrder(AVLNode* root);

void rotationUpdater(AVLNode* node, AVLNode* tp);

AVLNode* leftRotation(AVLNode* node);
AVLNode* rightRotation(AVLNode* node);
AVLNode* leftRightRotation(AVLNode* node);
AVLNode* rightLeftRotation(AVLNode* node);

AVLNode* rotationHelper(AVLNode* node);

AVLNode* AVLInsert(AVLNode*& root, int insertValue);

AVLNode* InsertNodes(int array[], int size, AVLNode* root);

#endif