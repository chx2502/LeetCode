//
//  main.cpp
//  LeetCode_236_二叉树的最近公共祖先
//
//  Created by chx on 2020/3/16.
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
    /*
     核心思路：
     p，q 的最近公共祖先分以下情况：
     1. p 是 q 的祖先， return p
     2. q 是 p 的祖先， return q
     3. p, q 同在 root 的左子树，递归地在左子树求解
     4. p, q 同在 root 的右子树，递归地在右子树求解
     5. p, q 分别在 root 的左右子树，return root
     **/
    bool searchNode(const TreeNode *root, const int target) {
        if (!root) return false;
        if (root->val == target) return true;
        else return searchNode(root->left, target) || searchNode(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (searchNode(p, q->val)) return p;
        if (searchNode(q, p->val)) return q;
        
        if (searchNode(root->left, p->val) && searchNode(root->left, q->val))
            return lowestCommonAncestor(root->left, p, q);
        if (searchNode(root->right, p->val) && searchNode(root->right, q->val))
            return lowestCommonAncestor(root->right, p, q);
        return root;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
