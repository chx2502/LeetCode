//
//  main.cpp
//  LeetCode_226_翻转二叉树
//
//  Created by chx on 2019/11/14.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode *temp = nullptr;
        if (root->left)
            temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
