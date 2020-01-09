//
//  main.cpp
//  LeetCode_230_二叉搜索树中第K小的元素
//
//  Created by chx on 2020/1/9.
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* CreateBinaryTree(vector<int>& val_array) {
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
    /*
     常规解法：
     中序遍历用数组 array 保存，返回 array[k-1]
     **/
    int kthSmallest(TreeNode* root, int k) {
        vector<int> array;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        while (!stk.empty() || p) {
            if (p) {
                stk.push(p);
                p = p->left;
            }
            else {
                p = stk.top();
                array.push_back(p->val);
                stk.pop();
                p = p->right;
            }
        }
        return array[k-1];
    }
};



int main(int argc, const char * argv[]) {
    vector<int> val_array = {3, 1, 4, NULL, 2};
    TreeNode *bst = CreateBinaryTree(val_array);
    Solution s;
    int result = s.kthSmallest(bst, 2);
    return 0;
}
