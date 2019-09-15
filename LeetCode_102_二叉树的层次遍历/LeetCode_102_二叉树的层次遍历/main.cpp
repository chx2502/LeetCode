//
//  main.cpp
//  LeetCode_102_二叉树的层次遍历
//
//  Created by 成鑫 on 2019/7/19.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//  两个队列实现，一个用于保存当前层的元素，一个用于接收下一层的元素。

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > ret;
        if (!root) return ret;
        queue<TreeNode*> queue_curr, queue_next;
        queue_curr.push(root);
        
        do {
            while(!queue_next.empty()) {
                queue_curr.push(queue_next.front());
                queue_next.pop();
            }
            
            vector<int> tmp;
            TreeNode *node;
            while(!queue_curr.empty()) {
                node = queue_curr.front();
                if (node->left) queue_next.push(node->left);
                if (node->right) queue_next.push(node->right);
                queue_curr.pop();
                tmp.push_back(node->val);
            }
            ret.push_back(tmp);
        } while(!queue_next.empty());
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
