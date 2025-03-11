#include<iostream>
typedef struct _CSNode{
    int data;
    struct _CSNode *firstchild,*nextsibling;
} CSNode, *CSTree;
// Function to search for a node with given data in the CSTree
CSNode* search(CSTree tree, int key) {
    if (tree == nullptr) {
        return nullptr;
    }
    if (tree->data == key) {
        return tree;
    }
    CSNode* result = search(tree->firstchild, key);
    if (result != nullptr) {
        return result;
    }
    return search(tree->nextsibling, key);
}
// Function to browse the CSTree and print each node's data
void browse(CSTree tree) {
    if (tree == nullptr) {
        return;
    }
    // Print the current node's data
    printf("%d ", tree->data);
    // Recursively browse the first child and next sibling
    browse(tree->firstchild);
    browse(tree->nextsibling);
}