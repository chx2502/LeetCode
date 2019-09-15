//
//  main.cpp
//  LeetCode_103_二叉树的锯齿形层次遍历
//
//  Created by 成鑫 on 2019/7/26.
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        stack<TreeNode*> s1, s2;
        const int LR = 0;
        const int RL = 1;
        int direction = RL;

        s1.push(root);
        do {
            TreeNode *node;
            vector<int> tmp;
            while (!s1.empty()) {
                node = s1.top();
                s1.pop();
                s2.push(node);
            }
            while (!s2.empty()) {
                node = s2.top();
                s2.pop();
                if (direction == LR) {
                    if (node->left) s1.push(node->left);
                    if (node->right) s1.push(node->right);
                } else {
                    if (node->right) s1.push(node->right);
                    if (node->left) s1.push(node->left);
                }
                tmp.push_back(node->val);
            }
            res.push_back(tmp);
            direction = !direction;
        } while (!s1.empty());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
