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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    vector<TreeNode*> creatBST(int begin, int end) {
        vector<TreeNode*> result;
        if (begin > end) result.push_back(nullptr);
        
        for (int i = begin; i <= end; ++i) {
            vector<TreeNode*> left_trees = creatBST(begin, i-1);
            vector<TreeNode*> right_trees = creatBST(i+1, end);
            for (auto &leftTree : left_trees) {
                for (auto &rightTree : right_trees) {
                    TreeNode *node = new TreeNode(i);
                    node->left = leftTree;
                    node->right = rightTree;
                    result.push_back(node);
                }
            }
        }
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if (n == 0) return result;
        result = creatBST(1, n);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
