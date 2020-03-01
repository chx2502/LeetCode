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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int length = (int)pre.size();
        if (length == 0) return NULL;
        TreeNode *root = new TreeNode(pre[0]);
        if (length == 1) return root;
        
        int left, right;
        left = pre[1];
        right = post[length-2];
    
        vector<int>::iterator pre_iter, post_iter;
        pre_iter = pre.begin()+1;
        post_iter = post.end()-2;
        while (*pre_iter != right && pre_iter < pre.end()) pre_iter++;
        while (*post_iter != left && post_iter > post.begin()) post_iter--;
        
        vector<int> left_pre(pre.begin()+1, pre_iter);
        vector<int> left_post(post.begin(), post_iter+1);
        vector<int> right_pre(pre_iter, pre.end());
        vector<int> right_post(post_iter+1, post.end());
        
        root->left = constructFromPrePost(left_pre, left_post);
        root->right = constructFromPrePost(right_pre, right_post);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
