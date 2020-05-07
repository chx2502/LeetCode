//
//  main.cpp
//  LeetCode_572
//
//  Created by chx on 2020/5/7.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    bool compareTrees(TreeNode *root, TreeNode *target) {
        if (!root && !target) return true;
        if (!root || !target) return false;
        
        if (root->val != target->val) return false;
        else
            return compareTrees(root->left, target->left)
            && compareTrees(root->right, target->right);
    }
    
    bool preorder(TreeNode *root, TreeNode *target) {
        if (!root) return false;
        bool result = false;
        if (root->val == target->val)
            result = compareTrees(root, target);
        if (result) return true;
        else {
            result = preorder(root->left, target) || preorder(root->right, target);
        }
        return result;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!t) return true;
        if (!s) return false;
        return preorder(s, t);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
