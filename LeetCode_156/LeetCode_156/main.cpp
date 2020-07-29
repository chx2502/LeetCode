//
//  main.cpp
//  LeetCode_156
//
//  Created by chx on 2020/7/29.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
//    void insertLeft(TreeNode* root, TreeNode *child) {
//        if (root->right) insertLeft(root->left, child);
//        else {
//            root->left = child;
//            return;
//        }
//    }
//
//    void insertRight(TreeNode* root, TreeNode *child) {
//        if (root->right) insertRight(root->right, child);
//        else {
//            root->right = child;
//            return;
//        }
//    }
    
    TreeNode* rightLeaf(TreeNode* root) {
        if (root->right) return rightLeaf(root->right);
        else return root;
    }
    
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode *left, *right;
        left = upsideDownBinaryTree(root->left);
        right = upsideDownBinaryTree(root->right);
        if (left) {
            root->left = nullptr;
            root->right = nullptr;
            TreeNode *leaf = rightLeaf(left);
            leaf->left = right;
            leaf->right = root;
            return left;
        } else {
            root->left = right;
            return root;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
