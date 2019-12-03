//
//  main.cpp
//  LeetCode_700_二叉搜索树中的搜索
//
//  Created by chx on 2019/12/1.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
     水题，注意不要用可能为空的指针去作为判断条件。
     **/
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root->val == val) return root;
        TreeNode *tree_ptr = root;
        int temp = tree_ptr->val;
        while(temp != val) {
            if (temp > val) tree_ptr = tree_ptr->left;
            if (temp < val) tree_ptr = tree_ptr->right;
            if (tree_ptr == nullptr) return NULL;
            temp = tree_ptr->val;
        }
        return tree_ptr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
