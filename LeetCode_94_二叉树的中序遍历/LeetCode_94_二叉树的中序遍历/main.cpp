//
//  main.cpp
//  LeetCode_94_二叉树的中序遍历
//
//  Created by 成鑫 on 2019/7/19.
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

/*
 两种实现：递归，非递归
 */

class Solution {
public:
    vector<int> res;
    //   递归实现
//    vector<int> inorderTraversal(TreeNode* root) {
//        if (!root) return res;
//        if (root->left) inorderTraversal(root->left);
//        res.push_back(root->val);
//        if (root->right) inorderTraversal(root->right);
//        return res;
//    }
    
    //  非递归实现：利用栈将所有左子树压入后出栈，出栈时记录节点值并压入右子树，直到栈为空
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return res;
        TreeNode *ptr = root;
        stack<TreeNode*> stack;
        
        while (ptr || !stack.empty()) {
            while (ptr) {
                stack.push(ptr);
                ptr = ptr->left;
            }
            ptr = stack.top();
            stack.pop();
            res.push_back(ptr->val);
            ptr = ptr->right;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
