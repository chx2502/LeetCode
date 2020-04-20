//
//  main.cpp
//  LeetCode_257_二叉树的所有路径
//
//  Created by chx on 2020/4/20.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(string curr, TreeNode* tree, vector<string>& result) {
        if (!tree) return;
        
        if (curr.length() == 0) curr += to_string(tree->val);
        else curr += "->" + to_string(tree->val);
        
        if (tree->left == nullptr && tree->right == nullptr) {
            result.push_back(curr);
            return;
        }
        
        dfs(curr, tree->left, result);
        dfs(curr, tree->right, result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        string curr = "";
        dfs(curr, root, result);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
