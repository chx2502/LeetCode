//
//  main.cpp
//  LeetCode_1315_祖父节点值为偶数的节点和
//
//  Created by chx on 2020/2/26.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <stack>

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
     栈实现二叉树的先序遍历，遍历到偶数结点时计算其孙子结点之和并累加到返回值上。
     **/
    int sumGrandchildren(TreeNode* root) {
        int result = 0;
        if (root->left) {
            if (root->left->left) result += root->left->left->val;
            if (root->left->right) result += root->left->right->val;
        }
        if (root->right) {
            if (root->right->left) result += root->right->left->val;
            if (root->right->right) result += root->right->right->val;
        }
        return result;
    }
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            if (node->right) stk.push(node->right);
            if (node->left)stk.push(node->left);
            if (node->val % 2 == 0) sum += sumGrandchildren(node);
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
