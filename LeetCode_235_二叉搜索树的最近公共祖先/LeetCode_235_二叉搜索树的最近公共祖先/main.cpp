//
//  main.cpp
//  LeetCode_235_二叉搜索树的最近公共祖先
//
//  Created by chx on 2020/3/1.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        int root_val, p_val, q_val;
        root_val = root->val;
        p_val = p->val;
        q_val = q->val;
        if ( p_val < root_val && q_val < root_val ) return lowestCommonAncestor(root->left, p, q);
        if ( p_val > root_val && q_val > root_val ) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
