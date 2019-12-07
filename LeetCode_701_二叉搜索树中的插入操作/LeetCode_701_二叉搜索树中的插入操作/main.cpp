//
//  main.cpp
//  LeetCode_701_二叉搜索树中的插入操作
//
//  Created by chx on 2019/12/5.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *node = new TreeNode(val);
        if (!root) return node;
        TreeNode *insert = root;
        while (true) {
            bool flag = false;
            if (insert->val > val) {
                if (insert->left) insert = insert->left;
                else {
                    insert->left = node;
                    flag = true;
                }
            }
            if (insert->val < val) {
                if (insert->right) insert = insert->right;
                else {
                    insert->right = node;
                    flag = true;
                }
            }
            if (flag) break;
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
