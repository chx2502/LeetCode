//
//  main.cpp
//  LeetCode_543_二叉树的直径
//
//  Created by chx on 2020/3/10.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
     DFS 递归解法
     **/
    
    int dfs(TreeNode *root, int& max_path) {
        if (!root) return 0;
        
        int left_depth, right_depth;
        left_depth = dfs(root->left, max_path);
        right_depth = dfs(root->right, max_path);
        
        int curr_depth = 1 + max(left_depth, right_depth);
        int curr_path = 1 + left_depth + right_depth;
        max_path = max_path < curr_path ? curr_path : max_path;
        
        return curr_depth;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int max_path = 0;
        dfs(root, max_path);
        return max_path-1;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
