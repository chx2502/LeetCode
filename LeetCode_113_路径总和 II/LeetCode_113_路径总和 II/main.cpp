//
//  main.cpp
//  LeetCode_113_路径总和 II
//
//  Created by chx on 2019/10/24.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

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
     由当前节点出发，分别在左右子树递归地寻找 (目标值-当前值) 路径，
     并将当前节点值加入到找到的路径数组最前端
     若没找到，直接返回长度为 0 的空数组
     */
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        if (!root) return ret;
        
        if (root->val == sum && !root->left && !root->right) {
            ret.push_back(vector<int>(1, root->val));
            return ret;
        }
        
        vector<vector<int>> left_matrix = pathSum(root->left, sum - root->val);
        vector<vector<int>> right_matrix = pathSum(root->right, sum - root->val);
        if (left_matrix.size() != 0) {
            for (auto arr : left_matrix) {
                arr.insert(arr.begin(), root->val);
                ret.push_back(arr);
            }
        }
        if (right_matrix.size() != 0) {
            for (auto arr : right_matrix) {
                arr.insert(arr.begin(), root->val);
                ret.push_back(arr);
            }
        }

        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
