//
//  main.cpp
//  LeetCode_337
//
//  Created by chx on 2020/8/5.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode*, vector<int>> memory;
    vector<int> action(TreeNode *root) {
        if (!root) return {0, 0};
        if (memory.find(root) != memory.end()) return memory[root];
        vector<int> result;
        vector<int> left_gain = action(root->left);
        vector<int> right_gain = action(root->right);
        result.push_back(root->val + left_gain[1] + right_gain[1]);
        result.push_back(
                         max(left_gain[0], left_gain[1]) +
                         max(right_gain[0], right_gain[1])
                         );
        memory[root] = result;
        return result;
    }
    
    int rob(TreeNode* root) {
        if (!root) return 0;
        vector<int> result = action(root);
        return max(result[0], result[1]);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
