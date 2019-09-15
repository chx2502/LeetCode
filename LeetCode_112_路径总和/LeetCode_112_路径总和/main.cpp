//
//  main.cpp
//  LeetCode_112_路径总和
//
//  Created by 成鑫 on 2019/8/4.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
};
/*
 核心思路：记录当前路径和，遍历到叶节点时同m目标 sum 作比较并返回，所有叶节点的结果求或。
 */
class Solution {
public:
    bool getSum(TreeNode *root, int curr_sum, int sum) {
        if (!root) return false;
        
        int tmp = curr_sum + root->val;
        if (root->left == NULL && root->right == NULL)
            return tmp == sum;
        else
            return getSum(root->left, tmp, sum) || getSum(root->right, tmp, sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return getSum(root, 0, sum);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
