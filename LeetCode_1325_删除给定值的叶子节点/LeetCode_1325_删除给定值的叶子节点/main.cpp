//
//  main.cpp
//  LeetCode_1325_删除给定值的叶子节点
//
//  Created by chx on 2020/2/20.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isLeaf(TreeNode *node) {
        if (!node) return true;
        if (node->left || node->right) return false;
        else return true;
    }
    
    /*
     核心思路：
     层序遍历二叉树，遇到符合删除条件的叶节点则删除该节点，
     一次遍历完后，若有删除操作发生，则再次遍历，知道无删除操作发生，即可返回 root
     注意：要考虑 root 本身为可删除节点的情况
     **/
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return root;
        bool flag = false;
        do {
            flag = false;
            queue<TreeNode*> Q;
            Q.push(root);
            while (!Q.empty()) {
                TreeNode *current = Q.front();
                Q.pop();
                if (isLeaf(current) && current->val == target) {
                    current = NULL;
                    return NULL;
                }
                if (current->left) {
                    if (!isLeaf(current->left)) Q.push(current->left);
                    else if (current->left->val == target) {
                        current->left = NULL;
                        flag = true;
                    }
                }
                if (current->right) {
                    if (!isLeaf(current->right)) Q.push(current->right);
                    else if (current->right->val == target) {
                        current->right = NULL;
                        flag = true;
                    }
                }
            }
        } while (flag);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
