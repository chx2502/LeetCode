//
//  main.cpp
//  LeetCode_1261_在受污染的二叉树中查找元素
//
//  Created by chx on 2020/2/28.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements {
private:
    TreeNode *tree;
    map<int, bool> M;
    
public:
    TreeNode *recoverTree(TreeNode *root) {
        if (!root) return NULL;
        this->M[root->val] = true;
        if (root->left) {
            root->left->val = 2*root->val + 1;
            recoverTree(root->left);
        }
        if (root->right) {
            root->right->val = 2*root->val + 2;
            recoverTree(root->right);
        }
        return root;
    }
    
    FindElements(TreeNode* root) {
        if (!root) this->tree = NULL;
        else {
            tree = root;
            tree->val = 0;
            tree = recoverTree(tree);
        }
    }
    
    bool find(int target) {
        return this->M[target];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
