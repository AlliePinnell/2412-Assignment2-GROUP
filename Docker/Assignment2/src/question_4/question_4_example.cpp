#include <iostream>
#include "question_4.hpp"

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