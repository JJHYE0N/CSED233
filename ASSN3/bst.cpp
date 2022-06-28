#include "tree.h"
#include "bst.h"
#include <iostream>
#include <string>

using namespace std;

int BinarySearchTree::insertion(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    Node* temp = new Node(key);
    Node* parent;
    parent = nullptr;
    int result;
    result=0;

    if (_root== nullptr) {
        _root=temp;
        return 0;
    }
    else {
        is_exist_node(_root,key,result,parent);
    }

    if(result==1) return -1;
    else {
        if(parent->key<key) parent->right=temp;
        else if(parent->key>key) parent->left=temp;
        return 0;
    }
    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int BinarySearchTree::deletion(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    Node *temp;
    Node *parent;
    parent = nullptr;
    int result;
    result = 0;

    is_exist_node(_root,key,result,parent);

    if (result == 0) return -1;
    else {
        if (_root->key == key) {
            temp = _root;
        }
        else {
            if (parent->left != nullptr && parent->left->key == key) {
                temp = parent->left;
            }
            if (parent->right != nullptr && parent->right->key == key) {
                temp = parent->right;
            }
        }
        int minimum;
        int num_children = has_children(temp);
        if (num_children == 2) {
            minimum = min_search(temp->right);
            deletion(minimum);
            temp->key = minimum;
        }
        else if (num_children == 1) {
            Node *_child;
            if (temp->left != nullptr) _child = temp->left;
            else if (temp->right != nullptr) _child = temp->right;

            if (_root == temp) _root = _child;
            else {
                if (parent->left == temp) parent->left = _child;
                else if (parent->right == temp) parent->right = _child;
            }
        }
        else if (num_children == 0) {
            if (temp == _root) _root = nullptr;
            else if (parent->left == temp) parent->left = nullptr;
            else if (parent->right == temp) parent->right = nullptr;
        }
        return 0;
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////
int BinarySearchTree::has_children(Node *root) {
    if(root->left != nullptr && root->right != nullptr) return 2;
    else if(root->left != nullptr && root->right == nullptr) return 1;
    else if(root->left == nullptr && root->right != nullptr) return 1;
    else return 0;
}

int BinarySearchTree::min_search(Node *root) {
    while(root->left!= nullptr) {
        root=root->left;
    }
    return root->key;
}

void BinarySearchTree::is_exist_node(Node* root, int key, int &result, Node* &parent) {
    if (root == nullptr) return;
    else if (root->key == key) {
        result = 1;
        return;
    }
    else if (root->key> key) {
        if (root->left == nullptr) {
            parent = root;
            return;
        }
        else if (root->left->key == key) {
            result = 1;
            parent = root;
            return;
        }
        is_exist_node(root->left, key, result, parent);
    }
    else if (root->key<key) {
        if (root->right == nullptr) {
            parent = root;
            return;
        }
        else if (root->right->key == key) {
            result = 1;
            parent = root;
            return;
        }
        is_exist_node(root->right, key, result, parent);
    }
}
/*  Write your codes if you have additional functions  */
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
