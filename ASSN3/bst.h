#pragma once
#include "tree.h"

using namespace std;

class BinarySearchTree: public BinaryTree {
public:
    BinarySearchTree() { };
    ~BinarySearchTree() { };

    int insertion(int key);
    int deletion(int key);

private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
protected:
    void is_exist_node(Node *root,int key,int &result, Node *&t);
    int has_children(Node *root);
    int min_search(Node *root);
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};