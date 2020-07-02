//
//  main.cpp
//  LeetCode_872
//
//  Created by chx on 2020/7/2.
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

class Solution {
public:
    bool isLeaf(TreeNode *node) {
        if (node->left == nullptr && node->right == nullptr) return true;
        else return false;
    }
    
    vector<TreeNode*> getLeaves(TreeNode *root) {
        vector<TreeNode*> result;
        if (!root) return result;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode *curr = stk.top();
            stk.pop();
            if (isLeaf(curr)) result.push_back(curr);
            else {
                if (curr->left) stk.push(curr->left);
                if (curr->right) stk.push(curr->right);
            }
        }
        
        return result;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*> leaves_array1 = getLeaves(root1);
        vector<TreeNode*> leaves_array2 = getLeaves(root2);
        if (leaves_array1.size() != leaves_array2.size()) return false;
        int size = (int)leaves_array1.size();
        for (int i = 0; i < size; ++i) {
            if (leaves_array1[i]->val != leaves_array2[i]->val) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
