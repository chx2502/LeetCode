//
//  main.cpp
//  LeetCode_106_从中序与后序遍历序列构造二叉树
//
//  Created by 成鑫 on 2019/8/1.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};

/*
 核心思路：
 参照先序遍历和中序遍历生成二叉树的思想，按后序遍历的逆序寻找根节点，递归时应先生成右子树再生成左子树
 
 边界条件：
 输入中存在空数组时，返回 NULL
 前序和中序数组元素数量不同时，返回 NULL
 中序遍历中，根节点左边或右边没有元素时，返回 NULL
 中序遍历中，根节点左边或右边只有一个元素时，直接返回该元素生成的 TreeNode*
 */


class Solution {
public:
    unsigned int post_idx;           //  全局变量 post_idx 用来指向下一个未收录的 postorder 元素，该元素即为下一个根节点
    TreeNode* findRoot(vector<int>& inorder, vector<int>& postorder, int begin, int end) {
        if (begin > end) return NULL;
        if (begin == end) {
            post_idx--;
            return new TreeNode(inorder[begin]);
        }
        TreeNode *root = new TreeNode(postorder[post_idx]);
        int mid = begin;
        for (int i = begin; i <= end; i++)
            if (inorder[i] == postorder[post_idx]) {
                mid = i;    //  寻找划分左右子树的中点
                break;
            }
        post_idx--;
        root->right = findRoot(inorder, postorder, mid+1, end);
        root->left = findRoot(inorder, postorder, begin, mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() != inorder.size()) return NULL;
        if (postorder.size() == 0 || inorder.size() == 0) return NULL;
        const int size = (int)postorder.size();
        int left = 0;
        int right = size - 1;
        post_idx = right;
        TreeNode *root = findRoot(inorder, postorder, left, right);
        return root;
    }
};

vector<int> preorder = {1, 2};
vector<int> inorder = {9, 3, 15, 20, 7};
vector<int> postorder = {9, 15, 7, 20, 3};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    TreeNode *result = s.buildTree(inorder, postorder);
    return 0;
}
