#include <iostream>
#include "question_2.hpp"

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