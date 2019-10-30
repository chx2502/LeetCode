//
//  main.cpp
//  LeetCode_199_二叉树的右视图
//
//  Created by chx on 2019/10/28.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {
public:
    /*
     核心思路：按从右到左层序遍历，取每层第一个数
     */
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        queue<TreeNode*> node_quque;
        node_quque.push(root);
        do {
            vector<TreeNode*> level;
            while(!node_quque.empty()) {
                TreeNode *node = node_quque.front();
                node_quque.pop();
                level.push_back(node);
            }
            ret.push_back(level[0]->val);
            for (auto t : level) {
                if (t->right) node_quque.push(t->right);
                if (t->left) node_quque.push(t->left);
            }
        } while(!node_quque.empty());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
