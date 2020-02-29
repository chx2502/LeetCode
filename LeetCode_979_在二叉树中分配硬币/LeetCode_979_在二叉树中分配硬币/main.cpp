//
//  main.cpp
//  LeetCode_979_在二叉树中分配硬币
//
//  Created by chx on 2020/2/29.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> array) {
    if (array.size() == 0) return NULL;
    vector<TreeNode*> nodes;
    TreeNode *dump = new TreeNode(0xFFFFFFFF);
    nodes.push_back(dump);
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == INT32_MIN) {
            nodes.push_back(NULL);
            continue;
        }
        TreeNode *node = new TreeNode(array[i]);
        nodes.push_back(node);
    }
    for (int i = 1; i < nodes.size(); i++) {
        TreeNode *temp = nodes[i];
        if (!temp) continue;
        if (i*2 < nodes.size()) temp->left = nodes[i*2];
        if (i*2 + 1 < nodes.size()) temp->right = nodes[i*2 + 1];
    }
    return nodes[1];
}

class Solution {
public:
    int result = 0;
    int dfs(TreeNode *root) {
        if (!root) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        result += abs(L) + abs(R);
        return root->val + L + R - 1;
    }
    int distributeCoins(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> array = {1, 0, 0, NULL, 3};
    TreeNode *tree = buildTree(array);
    int result = s.distributeCoins(tree);
    return 0;
}
