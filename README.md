# COMP-2412 Assignment 2; Deadline March 13th, 2026

Answer the following questions using C++. implement all data structures required for the 
solutions. Submit a single zip file containing the CMake project folder and solutions for all 
questions. In your zipfile also include a README document with complementary answers and 
the names of the executables for each questions. Please do not insert your build folder. Create 
one subdirectory per question and name them question_x fo the x questions. 

This assignment is worth 10 points. Each question is worth 2.5 points.

| Questions | C++ Code Completion | Docker Implementation | ❗FINAL REVIEW ❗|
| ----------- | ----------- | ----------- | ----------- |
| 1 a) | ✖️ | ✖️ | ✖️ 
| 1 b) | ✖️ | ✖️ | ✖️ 
| 2 a) | ✖️ | ✖️ | ✖️ 
| 2 b) | ✖️ | ✖️ | ✖️ 
| 2 c) | ✖️ | ✖️ | ✖️ 
| 3 a) | ✖️ | ✖️ | ✖️ 
| 3 b) | ✖️ | ✖️ | ✖️ 
| 4 a) | ✖️ | ✖️ | ✖️ 
| 4 b) | ✖️ | ✖️ | ✖️ 
| 4 c) | ✖️ | ✖️ | ✖️ 

# Questions for Thiago
| Questions | Response
| ----------- | ----------- 
| Account for dupes or no? | blank
| What structure in Q4? | blank

# Questions (copied from PDF)
# Question 1
**a)** Implement a BST in C/C++ using the given Node structure. Provide functions for insertion 
and searching for a value within the tree. Use the following structure: 
```
typedef struct Node { 
int value; 
struct Node* left; 
struct Node* right; 
} Node;
```

**b)** Given the sequences of numbers: 

&emsp;First sequence: 15, 10, 20, 8, 12, 17, 25 

&emsp;Second sequence: 50, 30, 70, 20, 40, 60, 80 

&emsp;For each sequence: 

&emsp;Draw the resulting BST if the numbers are inserted in the order given. 

&emsp;Implement and demonstrate inorder, preorder, and postorder traversals of the BST.  

&emsp;Explain the output of each traversal for both trees. 


# Question 2
**a)** Implement a C/C++ function to delete a node from a BST. The function should handle all 
three possible deletion scenarios: deleting a leaf node, a node with one child, and a node with 
two children. Use the Node structure defined previously. 

**b)** Given the sequence of numbers: 55, 40, 65, 30, 45, 60, 70, 42, 50, 58, 62, perform the 
following operations:

&emsp;I. Insert the numbers into a BST in the given order. 

&emsp;II. Implement inorder, preorder, and postorder traversals to print the BST. Explain what 
each traversal indicates about the tree structure. 

&emsp;III. Delete a node with two children (40), a node with one child (45), and a leaf node (30). 
After each deletion, perform inorder traversal to show the updated tree structure. 

**c)** For the BST obtained after the deletions in part b: 

&emsp;I. Implement a function to find the minimum value in the BST. 

&emsp;II. Implement a function to find the maximum value in the BST. 

&emsp;III. Discuss how the properties of BSTs make finding the minimum and maximum values efficiently. 

&emsp;*Instructions and Hints:*

> > For deletion, when you need to remove a node with two children, find the inorder 
successor (the smallest node in the right subtree) or the inorder predecessor (the largest node in 
the left subtree) to replace the deleted node's value, then delete the successor/predecessor node 
accordingly.

> > Make sure to handle the case where the node to be deleted is the root. 

> > For the traversals, explain that inorder traversal of a BST will give a sorted list of the values, preorder can be used to create a 
> > copy of the tree, and postorder can be used for deleting the tree. 

# Question 3
a) Define an AVL tree and explain the AVL tree rotation types with examples. Implement 
rotations in C/C++. 

b) Insert the following numbers into an AVL tree and describe or illustrate the tree after each 
insertion, noting any rotations that occur: 

&emsp;&emsp;Sequence: 10, 20, 30, 40, 50, 25

# Question 4 
a) Implement an AVL tree in C/C++ with insertion and balance correction. Use the following 
AVLNode structure: 

b) For the following sequences, insert the numbers into your AVL tree and document the tree's 
balance correction steps after each insertion: 

&emsp;&emsp;First sequence: 14, 17, 11, 7, 53, 4, 13 

&emsp;&emsp;Second sequence: 40, 20, 60, 10, 30, 50, 70

c) Implement and demonstrate the inorder, preorder, and postorder traversals for AVL trees. 
Explain how these traversals can be used to verify the correctness of your AVL tree 
implementation. 


# Alright, so Let's Get Started
