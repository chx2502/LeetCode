//
//  main.cpp
//  LeetCode_144_二叉树的前序遍历
//
//  Created by 成鑫 on 2019/7/21.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
//  分别实现递归和非递归解法
class Solution {
public:
    //  递归解法
    vector<int> res;
//    vector<int> preorderTraversal(TreeNode* root) {
//        if (!root) return res;
//        res.push_back(root->val);
//        if (root->left) preorderTraversal(root->left);
//        if (root->right) preorderTraversal(root->right);
//        return res;
//    }
    //  非递归解法
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return res;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode *node = stack.top();
            stack.pop();
            if (node->right) stack.push(node->right);
            if (node->left) stack.push(node->left);
            res.push_back(node->val);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
