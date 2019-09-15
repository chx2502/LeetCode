//
//  main.cpp
//  LeetCode_637_二叉树的层平均值
//
//  Created by 成鑫 on 2019/7/18.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        vector<double> res;
        
        if (!root) return res;
        q1.push(root);
        do {
            double sum = 0;
            int width = 0;
            while (!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                q2.push(node);
            }
            while (!q2.empty()) {
                TreeNode *node = q2.front();
                q2.pop();
                if (node->left) q1.push(node->left);
                if (node->right) q1.push(node->right);
                width += 1;
                sum += node->val;
            }
            res.push_back(sum / width);
        } while (!q1.empty());
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
