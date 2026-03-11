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

void rotationUpdater(AVLNode* node, AVLNode* tp) {
    updateHeightBF(node);
    updateHeightBF(tp);
}

//Left Rotation
AVLNode* leftRotation(AVLNode* node) {
    std::cout << "Before Rotation: ";
    traversePreOrder(node);
    std::cout << std::endl;

    AVLNode* tp = node->right;
    node->right = tp->left;
    tp->left = node;

    rotationUpdater(node, tp);

    std::cout << "After Rotation: ";
    traversePreOrder(tp);
    std::cout << std::endl << std::endl;

    return tp;
}

// Right Rotation
AVLNode* rightRotation(AVLNode* node) {
    std::cout << "Before Rotation: ";
    traversePreOrder(node);
    std::cout << std::endl;

    AVLNode* tp = node->left;
    node->left = tp->right;
    tp->right = node;

    rotationUpdater(node, tp);

    std::cout << "After Rotation: ";
    traversePreOrder(tp);
    std::cout << std::endl << std::endl;

    return tp;
}

// Left->Right Rotation
AVLNode* leftRightRotation(AVLNode* node) {
    node->left = leftRotation(node->left);
    std::cout << "-Right Rotation- (PreOrder)" << std::endl;
    return rightRotation(node);
}

// Right->Left Rotation
AVLNode* rightLeftRotation(AVLNode* node) {
    node->right = rightRotation(node->right);
    std::cout << "-Left Rotation- (PreOrder)" << std::endl;
    return leftRotation(node);
}

AVLNode* rotationHelper(AVLNode* node) {
    if (node->bf < -1 && node->right->bf <= 0) {
        std::cout << "-Left Rotation- (PreOrder)" << std::endl;
        return leftRotation(node);
    }

    if (node->bf > 1 && node->left->bf < 0) {
        std::cout << "-Left-Right Rotation- (PreOrder)" << std::endl;
        return leftRightRotation(node);
    }

    if (node->bf < -1 && node->right->bf > 0) {
        std::cout << "-Right-Left Rotation- (PreOrder)" << std::endl;
        return rightLeftRotation(node);
    }

    if (node->bf > 1 && node->left->bf >= 0) {
        std::cout << "-Right Rotation- (PreOrder)" << std::endl;
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

    root = rotationHelper(root);

    return root;
}

AVLNode* InsertNodes(int array[], int size, AVLNode* root) {
    for (int i = 0; i < size; i++) {
        root = AVLInsert(root, array[i]);
    }

    return root;
}