//
//  main.cpp
//  LeetCode_1008_先序遍历构造二叉树
//
//  Created by chx on 2019/12/2.
//  Copyright © 2019 __Ninja__. All rights reserved.
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
     递归解法:
     preorder 第一个元素为树根，
     [ 第二个元素， 第一个比树根大的元素 ) 为左子树，
     [ 第一个比树根大的元素, 最后一个元素 ] 为右子树，
     递归地生成左右子树
     **/
    TreeNode* buildTreeFromPre(vector<int>& preorder, int left, int right) {
        if (left > right) return NULL;
        TreeNode *root = new TreeNode(preorder[left]);
        if (left == right) return root;
        int i = left+1;
        while(preorder[i] < preorder[left]) {
            i++;
            if (i >= preorder.size()) break;
        }
        root->left = buildTreeFromPre(preorder, left+1, i-1);
        root->right = buildTreeFromPre(preorder, i, right);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return NULL;
        int length = (int)preorder.size();
        if (length == 1) return new TreeNode(preorder[0]);
        TreeNode *root = buildTreeFromPre(preorder, 0, (int)preorder.size()-1);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> preorder = {4, 2};
    Solution s;
    TreeNode *tree = s.bstFromPreorder(preorder);
//    vector<int> inorder = vector<int>(preorder.begin(), preorder.end());
//    sort(inorder.begin(), inorder.end(), [](const int &a, const int &b) {return a < b;});
//    vector<int> test1 = vector<int>(preorder.begin()+1, preorder.begin()+1);
//    if (test1.empty()) cout << "test1 is empty" << endl;
    return 0;
}
