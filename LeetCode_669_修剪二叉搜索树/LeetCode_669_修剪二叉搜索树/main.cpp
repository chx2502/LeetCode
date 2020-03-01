//
//  main.cpp
//  LeetCode_669_修剪二叉搜索树
//
//  Created by chx on 2020/3/1.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
     递归解法
     **/
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return NULL;
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        if (root->val < L || root->val > R) {
            if (root->left) return root->left;
            if (root->right) return root->right;
            return NULL;
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
