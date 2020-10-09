//
//  main.cpp
//  LeetCode_617_合并二叉树
//
//  Created by chx on 2019/11/13.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
//    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
//        if (t1 == nullptr && t2 == nullptr) return NULL;
//        TreeNode *root = new TreeNode(0);
//        if (t1 != nullptr) root->val += t1->val;
//        else t1 = new TreeNode(0);
//        if (t2 != nullptr) root->val += t2->val;
//        else t2 = new TreeNode(0);
//
//        if (t1->left && t2->left) root->left = mergeTrees(t1->left, t2->left);
//        else if (t1->left) root->left = mergeTrees(t1->left, new TreeNode(0));
//        else if (t2->left) root->left = mergeTrees(new TreeNode(0), t2->left);
//        if (t1->right && t2->right)root->right = mergeTrees(t1->right, t2->right);
//        else if (t1->right) root->right = mergeTrees(t1->right, new TreeNode(0));
//        else if (t2->right) root->right = mergeTrees(new TreeNode(0), t2->right);
//        return root;
//    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
    
    vector<int> level_tran(TreeNode *root) {
        vector<int> ret;
        if (!root) return ret;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        TreeNode *empty_node = new TreeNode(0);
        while (!node_queue.empty()) {
            TreeNode *node = node_queue.front();
            ret.push_back(node->val);
            node_queue.pop();
            if (node->left) {
                node_queue.push(node->left);
            }
            else {
                node_queue.push(empty_node);
            }
            if (node->right) {
                node_queue.push(node->right);
            }
            else {
                node_queue.push(empty_node);
            }
        }
        return ret;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    TreeNode *t1 = NULL;
    TreeNode *t2 = new TreeNode(1);
    TreeNode *result = s.mergeTrees(t1, t2);
    
    return 0;
}
