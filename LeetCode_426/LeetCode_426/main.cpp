//
//  main.cpp
//  LeetCode_426
//
//  Created by chx on 2021/3/1.
//

#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *head;
    Node *tail;
    void helper(Node* root) {
        if (!root) return;
        helper(root->left);
        if (tail) {
            tail->right = root;
            root->left = tail;
        } else head = root;
        tail = root;
        helper(root->right);
    }
    
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        helper(root);
        head->left = tail;
        tail->right = head;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
