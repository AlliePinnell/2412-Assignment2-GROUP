#include <iostream>
#include "question_1.hpp"

int main() {
    int firstSequence[7] = { 15, 10, 20, 8, 12, 17, 25 };
    int secondSequence[7] = { 50, 30, 70, 20, 40, 60, 80 };

    Node* firstRoot = nullptr;
    Node* secondRoot = nullptr;

    firstRoot = InsertNodes(firstSequence, 7, firstRoot);
    secondRoot = InsertNodes(secondSequence, 7, secondRoot);

    std::cout << " ----- InOrder Traversals ----- " << std::endl;
    std::cout << "First Sequence: ";
    traverseInOrder(firstRoot);
    std::cout << std::endl;
    std::cout << "Second Sequence: ";
    traverseInOrder(secondRoot);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PreOrder Traversals ----- " << std::endl;
    std::cout << "First Sequence: ";
    traversePreOrder(firstRoot);
    std::cout << std::endl;
    std::cout << "Second Sequence: ";
    traversePreOrder(secondRoot);
    std::cout << std::endl << std::endl;

    std::cout << " ----- PostOrder Traversals ----- " << std::endl;
    std::cout << "First Sequence: ";
    traversePostOrder(firstRoot);
    std::cout << std::endl;
    std::cout << "Second Sequence: ";
    traversePostOrder(secondRoot);
    std::cout << std::endl << std::endl;
}