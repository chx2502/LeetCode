//
//  main.cpp
//  LeetCode_1038_从二叉搜索树到更大和树
//
//  Created by chx on 2019/12/4.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
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
    void inorder(TreeNode *root, vector<TreeNode*> &ret) {
        if (!root) return;
//        if (root->right) inorder(root->right, ret);
//        ret.push_back(root);
//        if (root->left) inorder(root->left, ret);
        stack<TreeNode*> stk;
        TreeNode *p = root;
        do {
            while (p != nullptr) {
                stk.push(p);
                p = p->right;
            }
            if (!stk.empty()) {
                TreeNode *temp = stk.top();
                stk.pop();
                ret.push_back(temp);
                p = temp->left;
            }
        } while(!stk.empty() || p != nullptr);
        return;
    }
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return NULL;
        vector<TreeNode*> node_arr;
        inorder(root, node_arr);
        unsigned long length = node_arr.size();
        if (length == 1) return root;
        for (int i = 1; i < length; i++) {
            node_arr[i]->val += node_arr[i-1]->val;
        }
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
