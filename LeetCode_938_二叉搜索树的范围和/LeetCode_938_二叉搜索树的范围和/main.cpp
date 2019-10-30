//
//  main.cpp
//  LeetCode_938_二叉搜索树的范围和
//
//  Created by chx on 2019/10/23.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    /*
     题目描述误导性太强。
     */
public:
    /*
     注释掉的部分实现了输出路径上节点之和
     */
//    bool isInTree(TreeNode* root, int X) {
//        if (!root) return false;
//        if (root->val == X) return true;
//        if (root->val > X) return isInTree(root->left, X);
//        else return isInTree(root->right, X);
//    }
//
//    TreeNode *findSplit(TreeNode *root, int L, int R) {
//        if (!root) return NULL;
//        if (root->val == L || root->val == R) return root;
//        if (isInTree(root->left, L) && isInTree(root->right, R)) return root;
//        if (L < root->val && R < root->val) return findSplit(root->left, L, R);
//        else return findSplit(root->right, L, R);
//    }
//
//    void findPath(TreeNode *root, int X, stack<int> &path, char flag) {
//        if (!root) return;
//        if (root->val >= X && flag == '>') path.push(root->val);
//        if (root->val <= X && flag == '<') path.push(root->val);
//        if (root->val == X) return;
//        if (root->val > X) findPath(root->left, X, path, flag);
//        else findPath(root->right, X, path, flag);
//    }
//
//    int rangeSumBST(TreeNode* root, int L, int R) {
//        if (!root) return 0;
//        if (L == R) return 0;
//        TreeNode *split = findSplit(root, L, R);
//        if (!split) return 0;
//        stack<int> path;
//        path.push(split->val);
//
//        TreeNode *L_find, *R_find;
//        L_find = split->left;
//        R_find = split->right;
//        findPath(L_find, L, path, '>');
//        findPath(R_find, R, path, '<');
//        int ret = 0;
//        while(!path.empty()) {
//            ret += path.top();
//            path.pop();
//        }
//        return ret;
//    }
    void inorder_trav(TreeNode *root, vector<int>& array) {
        if (!root) return;
        inorder_trav(root->left, array);
        array.push_back(root->val);
        inorder_trav(root->right, array);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        vector<int> array;
        inorder_trav(root, array);
        int ret = 0;
        for (auto i : array) {
            if (i >= L && i <= R) ret += i;
            if (i > R) break;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode node1 = TreeNode(5);
    TreeNode node2 = TreeNode(5);
    TreeNode *p = &node1;
    cout << &node1 << endl << &node2 << endl << p << endl;
    cout << (&node1 == &node2) << endl;
    return 0;
}
