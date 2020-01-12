//
//  main.cpp
//  LeetCode_114_二叉树展开为链表
//
//  Created by chx on 2020/1/12.
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


class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (!root->left) root = root->right;
            else {
                TreeNode *pNode = root->left;
                while (pNode->right)
                    pNode = pNode->right;
                pNode->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> val_array = {1, 2, 5, 3, 4, NULL, 6};
    TreeNode *bt = CreateBinaryTree(val_array);
    s.flatten(bt);
    while (bt) {
        cout << bt->val << " ";
        bt = bt->right;
    }
    return 0;
}
