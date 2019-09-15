//
//  main.cpp
//  LeetCode_111_二叉树的最小深度
//
//  Created by 成鑫 on 2019/8/4.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};
/*
 核心思路：遍历每个叶子节点，同时记录该叶子节点的路径长度，若小于 min_depth 则更新 min_depth，最后返回 min_depth。
 边界条件：root == NULL 时返回 0。
 */
class Solution {
public:
    unsigned int min_depth = 0xFFFFFFFF;
    
    void minChildTree(TreeNode *root, int depth) {
        if (!root) return;
        TreeNode *left_child, *right_child;
        left_child = root->left;
        right_child = root->right;
        if (left_child == NULL && right_child == NULL) {
            if (depth + 1 < min_depth) min_depth = depth + 1;
        } else {
            minChildTree(root->left, depth + 1);
            minChildTree(root->right, depth + 1);
        }
    }
    
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        minChildTree(root, 0);
        return min_depth;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
