//
//  main.cpp
//  LeetCode_1302_层数最深叶子节点的和
//
//  Created by chx on 2020/2/26.
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
      核心思路：
      层序遍历，返回最后一层的元素和
      **/
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        int result = 0;
        queue<TreeNode*> current_level;
        queue<TreeNode*> next_level;
        current_level.push(root);
        do {
            result = 0;
            while (!next_level.empty()) {
                current_level.push(next_level.front());
                next_level.pop();
            }
            while (!current_level.empty()) {
                TreeNode *node = current_level.front();
                current_level.pop();
                result += node->val;
                if (node->left) next_level.push(node->left);
                if (node->right) next_level.push(node->right);
            }
        } while (!next_level.empty());
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
