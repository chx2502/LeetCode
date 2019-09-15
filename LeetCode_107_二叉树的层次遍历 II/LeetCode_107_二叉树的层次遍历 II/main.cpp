//
//  main.cpp
//  LeetCode_107_二叉树的层次遍历 II
//
//  Created by 成鑫 on 2019/7/19.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector< vector<int> > ret;
        stack< vector<int> > stack;
        if (!root) return ret;
        queue<TreeNode*> queue_curr, queue_next;
        queue_curr.push(root);
        
        do {
            while (!queue_next.empty()) {
                queue_curr.push(queue_next.front());
                queue_next.pop();
            }
            
            vector<int> tmp;
            TreeNode *node;
            while (!queue_curr.empty()) {
                node = queue_curr.front();
                if (node->left) queue_next.push(node->left);
                if (node->right) queue_next.push(node->right);
                queue_curr.pop();
                tmp.push_back(node->val);
            }
            stack.push(tmp);
        } while (!queue_next.empty());
        while (!stack.empty()) {
            ret.push_back(stack.top());
            stack.pop();
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
