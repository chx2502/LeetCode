//
//  main.cpp
//  LeetCode_889_根据前序和后序遍历构造二叉树
//
//  Created by chx on 2020/3/1.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
     递归版本
     **/
    int preIdx = 0;
    int postIdx = 0;
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode *root = new TreeNode(pre[preIdx++]);
        if (root->val != post[postIdx])
            root->left = constructFromPrePost(pre, post);
        if (root->val != post[postIdx])
            root->right = constructFromPrePost(pre, post);
        postIdx++;
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
