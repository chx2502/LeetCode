//
//  main.cpp
//  LeetCode_98
//
//  Created by chx on 2020/5/5.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    TreeNode* CreateBinaryTree(vector<int> val_array) {
        TreeNode *root = NULL;
        const long int size = val_array.size();
        if (size == 0) return root;

        vector<TreeNode*> node_array;
        node_array.push_back(NULL);
        for (int i = 0; i < size; i++) {
            if (val_array.at(i) != (int)NULL) {
                TreeNode *node = new TreeNode(val_array.at(i));
                node_array.push_back(node);
            } else node_array.push_back(NULL);
        }
        root = node_array.at(1);
        for (int i = 1; i <= size/2; i++) {
            TreeNode *node = node_array.at(i);
            if (!node) continue;
            int left_idx, right_idx;
            left_idx = i * 2;
            right_idx = i * 2 + 1;
            if (left_idx <= size) node->left = node_array.at(left_idx);
            if (right_idx <= size) node->right = node_array.at(right_idx);
        }
        return root;
    }

    
    vector<int> array;
    bool inorder(TreeNode* root) {
        if (!root) return true;
        bool left = inorder(root->left);
        if (!array.empty()) {
            if (root->val <= array.back())
                return false;
        }
        array.push_back(root->val);
        bool right = inorder(root->right);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (array.size() == 1) return true;
        
        return inorder(root);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {5, 1, 4, NULL, NULL, 3, 6};
    bool result = s.isValidBST(s.CreateBinaryTree(nums));
    return 0;
}
