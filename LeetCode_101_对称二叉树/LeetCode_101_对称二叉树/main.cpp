//
//  main.cpp
//  LeetCode_101_对称二叉树
//
//  Created by 成鑫 on 2019/7/25.
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

class Solution {
public:
    //  递归交换左右子树
    void swap_children(TreeNode *root) {
        if (!root) return;
        if (root->left) swap_children(root->left);
        if (root->right) swap_children(root->right);
        TreeNode *tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
    //  中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
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
    //  此解法有误，思想可能用于别的问题
//    bool isSymmetric(TreeNode* root) {
//        if (!root) return false;
////        TreeNode *left, *right;
////        left = root->left;
////        right = root->right;
//        swap_children(root->right);
//        vector<int> left = inorderTraversal(root->left);
//        vector<int> right = inorderTraversal(root->right);
//        if (left.size() != right.size()) return false;
//        else {
//            for (int i = 0; i < left.size(); i++)
//                if (left[i] != right[i])
//                    return false;
//            return true;
//        }
//    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
