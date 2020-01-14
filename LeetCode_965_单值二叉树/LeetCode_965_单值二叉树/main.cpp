//
//  main.cpp
//  LeetCode_965_单值二叉树
//
//  Created by chx on 2020/1/14.
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
    /*
     思路：队列实现层序遍历，与根节点值作比较，不相同则返回 false，成功遍历则返回 true
     **/
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        int target = root->val;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            TreeNode *front = node_queue.front();
            node_queue.pop();
            if (front->val != target) return false;
            if (front->left) node_queue.push(front->left);
            if (front->right) node_queue.push(front->right);
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
