#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* Insert(Node*& root, int insertValue) {
    if (root == nullptr)
    {
        root = new Node{ insertValue, nullptr, nullptr };
        return root;
    }
    if (insertValue < root->value)
    {
        root->left = Insert(root->left, insertValue);
    }
    else if (insertValue > root->value)
    {
        root->right = Insert(root->right, insertValue);
    }
    return root;
}

Node* Search(Node* root, int searchValue)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->value == searchValue)
    {
        return root;
    }
    if (searchValue < root->value) {
        return Search(root->left, searchValue);
    }
    if (searchValue > root->value) {
        return Search(root->right, searchValue);
    }
    return nullptr;
}

void traversePreOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->value << " ";
    traversePreOrder(root->left);
    traversePreOrder(root->right);
}

void traverseInOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    traverseInOrder(root->left);
    std::cout << root->value << " ";
    traverseInOrder(root->right);
}

void traversePostOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    traversePostOrder(root->left);
    traversePostOrder(root->right);
    std::cout << root->value << " ";
}

Node* InsertNodes(int array[], int size, Node* root) {
    for (int i = 0; i < size; i++) {
        root = Insert(root, array[i]);
    }

    return root;
}

int main() {
    int firstSequence[7] = { 15, 10, 20, 8, 12, 17, 25 };
    int secondSequence[7] = { 50, 30, 70, 20, 40, 60, 80 };

    Node* firstRoot = nullptr;
    Node* secondRoot = nullptr;

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