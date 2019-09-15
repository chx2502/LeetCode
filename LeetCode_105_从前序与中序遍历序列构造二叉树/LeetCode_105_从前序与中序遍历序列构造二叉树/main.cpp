//
//  main.cpp
//  LeetCode_105_从前序与中序遍历序列构造二叉树
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
 由先序遍历和中序遍历的性质可知，先序遍历为寻找根节点的顺序
 中序遍历中，根节点之前的元素都属于左子树，右边的都属于右子树
 问题可转化为在中序遍历数组内寻找根节点，之后递归地生成左右子树
 
 边界条件：
 输入中存在空数组时，返回 NULL
 前序和中序数组元素数量不同时，返回 NULL
 中序遍历中，根节点左边或右边没有元素时，返回 NULL
 中序遍历中，根节点左边或右边只有一个元素时，直接返回该元素生成的 TreeNode*
 */


class Solution {
public:
    unsigned int pre_idx;           //  全局变量 pre_idx 用来指向下一个未收录的 preorder 元素，该元素即为下一个根节点
    TreeNode* findRoot(vector<int>& preorder, vector<int>& inorder, int begin, int end) {
        if (begin > end) return NULL;
        if (begin == end) {
            pre_idx++;
            return new TreeNode(inorder[begin]);
        }
        TreeNode *root = new TreeNode(preorder[pre_idx]);
        int mid = begin;
        for (int i = begin; i <= end; i++)
            if (inorder[i] == preorder[pre_idx]) {
                mid = i;    //  寻找划分左右子树的中点
                break;
            }
        pre_idx++;
        root->left = findRoot(preorder, inorder, begin, mid-1);
        root->right = findRoot(preorder, inorder, mid+1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size()) return NULL;
        if (preorder.size() == 0 || inorder.size() == 0) return NULL;
        const int size = (int)preorder.size();
        int left = 0;
        int right = size - 1;
        pre_idx = 0;
        TreeNode *root = findRoot(preorder, inorder, left, right);
        return root;
    }
};

vector<int> preorder = {1, 2};
vector<int> inorder = {1, 2};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    TreeNode *result = s.buildTree(preorder, inorder);
    return 0;
}
