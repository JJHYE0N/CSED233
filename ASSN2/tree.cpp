#include "tree.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/* This is given function. DO NOT MODIFY THIS FUNCTION */
int findIndex(const char *str, int start, int end) {
  if (start > end)
    return -1;

  string s;

  for (int i = start; i <= end; i++) {

    // if open parenthesis, push it
    if (str[i] == '(')
      s.push_back(str[i]);

    // if close parenthesis
    else if (str[i] == ')') {
      if (s.back() == '(') {
        s.pop_back();

        if (!s.length())
          return i;
      }
    }
  }
  // if not found return -1
  return -1;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
Node *BinaryTree::_buildFromString(const char *data, int start, int end) {
  if (start > end)
    return NULL;

  Node *root = new Node(data[start]);
  int index = -1;

  if (start + 1 <= end && data[start + 1] == '(')
    index = findIndex(data, start + 1, end);

  if (index != -1) {
    root->left = _buildFromString(data, start + 2, index - 1);
    root->right = _buildFromString(data, index + 2, end - 1);
  }
  return root;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void BinaryTree::buildFromString(const char *data) {
  Node *root = _buildFromString(data, 0, strlen(data) - 1);
  _root = root;
}

string BinaryTree::preOrder() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  std::string _pre;
  _preOrder(_root,_pre);
  return _pre;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::postOrder() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  std::string _post;
  _postOrder(_root, _post);
  return _post;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::inOrder() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  std::string _in;
  _inOrder(_root, _in);
  return _in;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

int BinaryTree::getDepth(int node_value) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  int answer = -1;
  char n = char(node_value + '0');
  _getDepth(_root, 0, n, answer);
  return answer;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

bool BinaryTree::isProper() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  bool _pro = true;
  _isProper(_root,_pro);
  return _pro;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional private functions  */
void BinaryTree::_preOrder(Node* root, string &_pre) {
    if (root != NULL) {
        _pre += root->value;
        _pre += " ";
        _preOrder(root->left, _pre);
        _preOrder(root->right, _pre);
    }
}
void BinaryTree::_postOrder(Node* root, string &_post) {
    if (root != NULL) {
        _postOrder(root->left, _post);
        _postOrder(root->right, _post);
        _post += root->value;
        _post += " ";
    }
}
void BinaryTree::_inOrder(Node* root, string &_in) {
    if (root != NULL) {
    _inOrder(root->left, _in);
    _in += root->value;
    _in += " ";
    _inOrder(root->right, _in);
    }
}
void BinaryTree::_getDepth(Node* root, int index, char target, int &answer) {
    if (root != NULL) {
        if (root->value == target) {
            answer = index;
        }
            _getDepth(root->left, index +1, target, answer);
            _getDepth(root->right, index +1, target, answer);
    }

}
void BinaryTree::_isProper(Node* root, bool &_pro) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {

        }
        else if (root->left != NULL && root->right != NULL) {
            _isProper(root->left, _pro);
            _isProper(root->right, _pro);
        }
        else {
            _pro = false;
        }

    }
}
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////