//
//  main.cpp
//  LeetCode_95_不同的二叉搜索树 II
//
//  Created by chx on 2020/4/20.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<vector<vector<TreeNode*>>> memory;
public:
    
//    vector<TreeNode*> createBST(int begin, int end) {
//        vector<TreeNode*> result;
//        if (begin > end) result.push_back(nullptr);
//
//        for (int i = begin; i <= end; ++i) {
//            vector<TreeNode*> left_trees = createBST(begin, i-1);
//            vector<TreeNode*> right_trees = createBST(i+1, end);
//            for (auto &leftTree : left_trees) {
//                for (auto &rightTree : right_trees) {
//                    TreeNode *node = new TreeNode(i);
//                    node->left = leftTree;
//                    node->right = rightTree;
//                    result.push_back(node);
//                }
//            }
//        }
//        return result;
//    }
    // 记忆化 + 递归
    vector<TreeNode*> createBstWithMemory(int begin, int end) {
        if (begin > end) return {nullptr};
        if (!memory[begin][end].empty()) return memory[begin][end];
        vector<TreeNode*> result;
        for (int i = begin; i <= end; i++) {
            for (auto &left : createBstWithMemory(begin, i-1))
                for (auto &right : createBstWithMemory(i+1, end)) {
                    TreeNode *root = new TreeNode(i, left, right);
                    result.push_back(root);
                }
        }
        memory[begin][end] = result;
        return memory[begin][end];
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if (n == 0) return result;
//        result = createBST(1, n);
        memory.resize(n+1, vector<vector<TreeNode*>>(n+1));
        result = createBstWithMemory(1, n);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<TreeNode*> result = s.generateTrees(4);
    return 0;
}
