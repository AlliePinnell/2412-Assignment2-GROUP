// An AVL Tree is a self-balancing Binary Search Tree that uses a balance factor 
// (the height difference between left and right subtrees) to maintain a balance 
// between -1 and 1 at every node, ensuring O(log n) search, insertion, and deletion.

// There are 4 types of AVL tree rotations
// 
    // 1. Left Rotation
    /*
        When the root has a right-heavy balance factor (negative balance factor) and the
        child node has a right-heavy balance factor (negative balance factor), you have to
        change the child node to be the root and then the root has to be the child on the
        left side.

                      Example
            ----------------------------
                 1                      
                  \                2 
                   2      =>      / \
                    \            1   3
                     3
    */

    // 2. Left->Right Rotation
    /*
        When the root has a left-heavy balance factor (positive balance factor) and the
        child node has a right-heavy balance factor (negative balance factor), you have to
        swap the child and the subchild and then perform a right rotation

                         Example
            --------------------------------
                 3          3
                /          /          2
               1    =>    2    =>    / \
                \        /          1   3
                 2      1
    */

    // 3. Right->Left Rotation
    /*
        When the root has a right-heavy balance factor (negative balance factor) and the
        child node has a left-heavy balance factor (positive balance factor), you have to
        swap the child and the subchild and then perform a left rotation

                         Example
            --------------------------------
              1          1
               \          \            2
                3    =>    2    =>    / \
               /            \        1   3
              2              3
    */

    // 4. Right Rotation
    /*
        When the root has a left-heavy balance factor (negative balance factor) and the
        child node has a left-heavy balance factor (negative balance factor), you have to
        change the child node to be the root and then the root has to be the child on the
        left side.

                      Example
            ----------------------------
                    3
                   /              2 
                  2      =>      / \
                 /              1   3
                1
    */


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

AVLNode* AVLinsertion(AVLNode* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (root->value == value) {
        root->counter++;
        return root;
    }

    if (value > root->value) {
        root->right = AVLinsertion(root->right, value);
    }
    else if (value < root->value) {
        root->left = AVLinsertion(root->left, value);
    }
   
    updateHeightBF(root);
    return rotationHelper(root);
}


// cut this
    // Function to print the tree
    void printAVL(AVLNode* root, string prefix = "", bool isLeft = true) {
        if (root == nullptr)
            return;

        if (root->right)
            printAVL(root->right, prefix + (isLeft ? "|   " : "    "), false);

        cout << prefix;
        cout << (isLeft ? "|__ " : "|-- ");
        cout << root->value << "(h=" << root->height << ", bf=" << root->bf << ")" << endl;

        if (root->left)
            printAVL(root->left, prefix + (isLeft ? "    " : "|   "), true);
    }


int main()
{
    AVLNode* root = nullptr;
    root = AVLinsertion(root, 10);
    root = AVLinsertion(root, 20);
    root = AVLinsertion(root, 30);
    root = AVLinsertion(root, 40);
    root = AVLinsertion(root, 50);
    root = AVLinsertion(root, 25);

    cout << "AVL Tree Structure:\n";
    printAVL(root);  // Print the tree
}