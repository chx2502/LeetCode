//
//  main.cpp
//  LeetCode_124
//
//  Created by chx on 2020/7/15.
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

class Solution {
public:
    int maxSum = -0x3f3f3f3f;
    
    int dfs(TreeNode *root) {
        if (!root) return 0;
        
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        
        int total = root->val + left + right;
        maxSum = max(maxSum, total);
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
