//
//  main.cpp
//  LeetCode_662_树的最大宽度
//
//  Created by 成鑫 on 2019/1/10.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        int leftW, rightW;
        leftW = widthOfBinaryTree(root->left);
        rightW = widthOfBinaryTree(root->right);
        return leftW + rightW;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
