//
//  main.cpp
//  LeetCode_104_二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        int res = 0;
        if (!root) return res;
        int left_depth, right_depth;
        left_depth = right_depth = 1;
        if (root->left) left_depth = left_depth + maxDepth(root->left);
        if (root->right) right_depth = right_depth + maxDepth(root->right);
        res = left_depth > right_depth ? left_depth : right_depth;
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
