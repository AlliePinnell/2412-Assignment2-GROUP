#include <iostream>
#include "question_3.hpp"

int main()
{
    AVLNode* root = nullptr;
    int numbers[] = { 10, 20, 30, 40, 50, 25 };

    root = InsertNodes(numbers, 6, root);

    std::cout << " ----- InOrder Traversals ----- " << std::endl;
    traverseInOrder(root);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PreOrder Traversals ----- " << std::endl;
    traversePreOrder(root);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PostOrder Traversals ----- " << std::endl;
    traversePostOrder(root);
    std::cout << std::endl << std::endl;
}