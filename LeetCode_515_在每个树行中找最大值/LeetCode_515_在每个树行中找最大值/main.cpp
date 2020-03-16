//
//  main.cpp
//  LeetCode_515_在每个树行中找最大值
//
//  Created by chx on 2020/3/16.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
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
     核心思路：
     两个队列实现层序遍历，记录每一层的最大值并加入 result 中。
     **/
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q2.push(root);
        do {
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
            int max = INT_MIN;
            while (!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                max = max < node->val ? node->val : max;
                if (node->left) q2.push(node->left);
                if (node->right) q2.push(node->right);
            }
            result.push_back(max);
        } while (!q2.empty());
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
