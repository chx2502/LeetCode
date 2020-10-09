//
//  main.cpp
//  LeetCode_99
//
//  Created by chx on 2020/8/8.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> inorderTraversal(TreeNode *root) {
        if (!root) return {};
        stack<TreeNode*> stk;
        vector<TreeNode*> result;
        TreeNode *curr = root;
        while (curr || !stk.empty()) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                TreeNode *node = stk.top();
                curr = node->right;
                result.push_back(node);
                stk.pop();
            }
        }
        return result;
    }
    
    void recoverTree(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> inorder_array = inorderTraversal(root);
        int pos = 0;
        vector<TreeNode*> incorrect;
        for (auto &node : inorder_array) {
            pos += 1;
            if (node->val != pos) incorrect.push_back(node);
        }
        swap(incorrect[0]->val, incorrect[1]->val);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
