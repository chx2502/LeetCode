//
//  main.cpp
//  LeetCode_814_二叉树剪枝
//
//  Created by chx on 2019/12/2.
//  Copyright © 2019 __Ninja__. All rights reserved.
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
     核心思路：
     递归判断树中有没有 1，有则对其左右子树分别剪枝，没有则返回空
     **/
    bool haveOne(TreeNode* root) {
        if (!root) return false;
        if (root->val == 1) return true;
        else return haveOne(root->left) || haveOne(root->right);
    }
    
    TreeNode* prune(TreeNode* root) {
        if (!root) return NULL;
        if (haveOne(root)) {
            if (root->left)
                root->left = prune(root->left);
            if (root->right)
                root->right = prune(root->right);
            return root;
        }
        else return NULL;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return NULL;
        root = prune(root);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
