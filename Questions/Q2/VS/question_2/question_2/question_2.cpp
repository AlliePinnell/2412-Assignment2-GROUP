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

Node* findSuccessor(Node* currentPoint)
{
    if (currentPoint == nullptr)
    {
        return nullptr;
    }
    if (currentPoint->left == nullptr)
    {
        return currentPoint;
    }
    return findSuccessor(currentPoint->left);
}

Node* findPredecessor(Node* currentPoint)
{
    if (currentPoint == nullptr)
    {
        return nullptr;
    }
    if (currentPoint->right == nullptr)
    {
        return currentPoint;
    }
    return findPredecessor(currentPoint->right);
}

Node* deleteNode(Node*& currentNode, int deleteValue) {
    if (currentNode == nullptr)
    {
        return nullptr;
    }
    else if (deleteValue < currentNode->value) {
        currentNode->left = deleteNode(currentNode->left, deleteValue);
    }
    else if (deleteValue > currentNode->value) {
        currentNode->right = deleteNode(currentNode->right, deleteValue);
    }
    else {
        if (currentNode->left == nullptr && currentNode->right == nullptr) {
            delete currentNode;
            return nullptr;
        }
        if (currentNode->left == nullptr)
        {
            Node* replacementNode = currentNode->right;
            delete currentNode;
            return replacementNode;

        }
        if (currentNode->right == nullptr)
        {
            Node* replacementNode = currentNode->left;
            delete currentNode;
            return replacementNode;
        }

        Node* largestSmall = findPredecessor(currentNode->left);
        currentNode->value = largestSmall->value;
        currentNode->left = deleteNode(currentNode->left, largestSmall->value);
    }

    return currentNode;

}

Node* findSmallest(Node* currentPoint)
{
    if (currentPoint == nullptr)
    {
        return nullptr;
    }
    if (currentPoint->left == nullptr)
    {
        return currentPoint;
    }
    return findSmallest(currentPoint->left);
}

Node* findLargest(Node* currentPoint)
{
    if (currentPoint == nullptr)
    {
        return nullptr;
    }
    if (currentPoint->right == nullptr)
    {
        return currentPoint;
    }
    return findLargest(currentPoint->right);
}

Node* InsertNodes(int array[], int size, Node* root) {
    for (int i = 0; i < size; i++) {
        root = Insert(root, array[i]);
    }

    return root;
}

int main()
{
    Node* rootThree = nullptr;
    int numbers[] = { 55, 40, 65, 30, 45, 60, 70, 42, 50, 58, 62 };

    rootThree = InsertNodes(numbers, 11, rootThree);

    //third sequence traverse
    std::cout << " ----- InOrder Traversals ----- " << std::endl;
    traverseInOrder(rootThree);
    std::cout << std::endl << std::endl;
    traverseInOrder(rootThree);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PreOrder Traversals ----- " << std::endl;
    traversePreOrder(rootThree);
    std::cout << std::endl << std::endl;
    traversePreOrder(rootThree);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PostOrder Traversals ----- " << std::endl;
    traversePostOrder(rootThree);
    std::cout << std::endl << std::endl;
    traversePostOrder(rootThree);
    std::cout << std::endl << std::endl;

    //delete 40
    deleteNode(rootThree, 40);
    std::cout << std::endl << " - Updated InOrder (Deleted 40) - " << std::endl;
    traverseInOrder(rootThree);
    std::cout << std::endl;

    //delete 45
    deleteNode(rootThree, 45);
    std::cout << std::endl << " - Updated InOrder (Deleted 45) - " << std::endl;
    traverseInOrder(rootThree);
    std::cout << std::endl;

    //delete 30
    deleteNode(rootThree, 30);
    std::cout << std::endl << "- Updated InOrder (Deleted 30) - " << std::endl;
    traverseInOrder(rootThree);
    std::cout << std::endl;
}
