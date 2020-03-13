//
//  main.cpp
//  LeetCode_103_二叉树的锯齿形层次遍历
//
//  Created by chx on 2020/3/13.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <queue>
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
    /*
     核心思路：
     双队列实现层序遍历，每一层生成一个数组
     根据题目描述，将奇数层（树根视为第 0 层）的遍历结果逆序，随后返回结果。
     **/
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q2.push(root);
        
        do {
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
            vector<int> temp;
            while (!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                if (node->left) q2.push(node->left);
                if (node->right) q2.push(node->right);
                temp.push_back(node->val);
            }
            result.push_back(temp);
        } while (!q2.empty());
        int size = (int)result.size();
        for (int i = 0; i < size; ++i) {
            if (i % 2) reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
