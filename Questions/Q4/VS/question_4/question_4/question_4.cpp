#include <iostream>
#include <algorithm>
using namespace std;

struct AVLNode {
    int value;
    int bf;
    int height;
    int counter;
    struct AVLNode* left;
    struct AVLNode* right;
};
AVLNode* createNode(int value) {
    AVLNode* newNode = new AVLNode();
    newNode->value = value;
    newNode->bf = 0;
    newNode->height = 1;
    newNode->counter = 0;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

int updateHeightBF(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }

    node->bf = updateHeightBF(node->left) - updateHeightBF(node->right);
    node->height = max(updateHeightBF(node->left), updateHeightBF(node->right)) + 1;

    return node->height;
}

void rotationUpdater(AVLNode* node, AVLNode* tp) {
    updateHeightBF(node);
    updateHeightBF(tp);
}

//Left Rotation
AVLNode* leftRotation(AVLNode* node) {
    AVLNode* tp = node->right;
    node->right = tp->left;
    tp->left = node;

    rotationUpdater(node, tp);

    return tp;
}

// Right Rotation
AVLNode* rightRotation(AVLNode* node) {
    AVLNode* tp = node->left;
    node->left = tp->right;
    tp->right = node;

    rotationUpdater(node, tp);

    return tp;
}

// Left->Right Rotation
AVLNode* leftRightRotation(AVLNode* node) {
    AVLNode* tp = node->left;
    node->left = tp->right;
    node->left->left = tp;

    return rightRotation(node);
}

// Right->Left Rotation
AVLNode* rightLeftRotation(AVLNode* node) {
    AVLNode* tp = node->right;
    node->right = tp->left;
    node->right->right = tp;

    return leftRotation(node);
}


AVLNode* rotationHelper(AVLNode* node) {
    if (node->bf < -1 && node->right->bf < -1) {
        return leftRotation(node);
    }
    if (node->bf > 1 && node->left->bf < -1) {
        return leftRightRotation(node);
    }
    if (node->bf < -1 && node->right->bf > 1) {
        return rightLeftRotation(node);
    }
    if (node->bf > 1 && node->left->bf > 1) {
        return rightRotation(node);
    }
    return node;
}

AVLNode* AVLInsert(AVLNode* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (root->value == value) {
        root->counter++;
        return root;
    }

    if (value > root->value) {
        root->right = AVLInsert(root->right, value);
    }
    else if (value < root->value) {
        root->left = AVLInsert(root->left, value);
    }

    updateHeightBF(root);
    return rotationHelper(root);
}

AVLNode* InsertNodes(int array[], int size, AVLNode* root) {
    for (int i = 0; i < size; i++) {
        root = AVLInsert(root, array[i]);
    }

    return root;
}

void traversePreOrder(AVLNode* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->value << " ";
    traversePreOrder(root->left);
    traversePreOrder(root->right);
}

void traverseInOrder(AVLNode* root) {
    if (root == nullptr) {
        return;
    }
    traverseInOrder(root->left);
    std::cout << root->value << " ";
    traverseInOrder(root->right);
}

void traversePostOrder(AVLNode* root) {
    if (root == nullptr) {
        return;
    }
    traversePostOrder(root->left);
    traversePostOrder(root->right);
    std::cout << root->value << " ";
}

int main()
{
    AVLNode* firstRoot = nullptr;
    AVLNode* secondRoot = nullptr;
    int firstSequence[7] = { 14, 17, 11, 7, 53, 4, 13 };
    int secondSequence[7] = { 40, 20, 60, 10, 30, 50, 70 };

    firstRoot = InsertNodes(firstSequence, 7, firstRoot);
    secondRoot = InsertNodes(secondSequence, 7, secondRoot);

    std::cout << " ----- InOrder Traversals ----- " << std::endl;
    traverseInOrder(firstRoot);
    std::cout << std::endl << std::endl;
    traverseInOrder(secondRoot);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PreOrder Traversals ----- " << std::endl;
    traversePreOrder(firstRoot);
    std::cout << std::endl << std::endl;
    traversePreOrder(secondRoot);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PostOrder Traversals ----- " << std::endl;
    traversePostOrder(firstRoot);
    std::cout << std::endl << std::endl;
    traversePostOrder(secondRoot);
    std::cout << std::endl << std::endl;
}