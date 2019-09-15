//
//  main.cpp
//  LeetCode_110_平衡二叉树
//
//  Created by 成鑫 on 2019/7/28.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x): val(x), left(NULL), right(NULL), parent(NULL) {};
};

class Solution {
public:
    int HeightOfTree(TreeNode *T) {
        if (!T) return 0;
        
        int L_Height, R_Height, Max_Height;
        L_Height = HeightOfTree(T->left);
        R_Height = HeightOfTree(T->right);
        Max_Height = L_Height > R_Height ? L_Height : R_Height;
        return Max_Height + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (fabs(HeightOfTree(root->left) - HeightOfTree(root->right)) > 1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
