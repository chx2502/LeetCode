//
//  main.cpp
//  LeetCode_897_递增顺序查找树
//
//  Created by chx on 2020/3/11.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
     核心思路：
     递归。
     如果 root 没有左子树，则无需改造，直接返回
     递归地改造 root->left, root->right
     记录递归后的 root->left 为 result，然后将 root 变为 root->left 最右边子树的右子树
     修改 root->left = NULL 指空，返回 result
     **/
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return NULL;
        if (!root->left) return root;
        
        root->left = increasingBST(root->left);
        if(root->right) root->right  = increasingBST(root->right);
        
        TreeNode *result = root->left;
        TreeNode *p = result;
        while (p->right) p = p->right;
        root->left = NULL;
        p->right = root;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
