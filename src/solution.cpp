#include "solution.h"
#include <iostream>
#include <vector>

int countElements(Node* tree) {
    if(!tree) return 0;

    return 1 + countElements(tree->left) + countElements(tree->right);
}

int countLeafs(Node* tree) {
    if (!tree) return 0;
    if (!tree->left && !tree->right) return 1;
    return countLeafs(tree->left) + countLeafs(tree->right);
}

int height(Node* tree) {
    if (!tree) return 0;

    return 1 + std::max(height(tree->left), height(tree->right));
}

int sumElements(Node* tree) {
   if (!tree) return 0;

    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}

int sumElementsAtLevel(Node* tree, unsigned level) {
    if (!tree) return 0;
    if (!level) return tree->key;

    return sumElementsAtLevel(tree->left, level - 1) 
        + sumElementsAtLevel(tree->right, level - 1);
}
bool helperFunction(Node* leftTree, Node* rightTree)
{
    if (!leftTree && !rightTree) return true;

    if (!leftTree || !rightTree) return false;

    if (leftTree->key == rightTree->key)
        return helperFunction(leftTree->right, rightTree->left) &&
        helperFunction(leftTree->left, rightTree->right);

    return false;
}

bool isSymmetric(Node* tree) {
    if (!tree) return true;
    if (!tree->left && !tree->right) return true;
    return helperFunction(tree->left, tree->right);
    
}

void getInOrder(Node* tree , std::vector<int>& res)
{
    if(!tree) return;

    getInOrder(tree->left,res);

    res.push_back(tree->key);

    getInOrder(tree->right,res);
}

bool isSorted (std::vector<int>& res)
{
    size_t size = res.size();

    for (size_t i = 0 ; i < size - 1 ; i++)
    {
        if(res[i] > res[i + 1]) return false;
    }

    return true;
}

bool isBST(Node* tree) {
   std::vector<int> inOrder;
   getInOrder(tree,inOrder);
   return isSorted(inOrder);
}