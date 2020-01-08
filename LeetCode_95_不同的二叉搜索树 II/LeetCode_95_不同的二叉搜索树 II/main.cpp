//
//  main.cpp
//  LeetCode_95_不同的二叉搜索树 II
//
//  Created by chx on 2019/12/12.
//  Copyright © 2019 __Ninja__. All rights reserved.
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
    vector<TreeNode*> buildTrees(int begin, int end, vector<int>& nums) {
        vector<TreeNode*> trees;
        if (begin > end) return trees;
        if (begin == end) {
            trees.push_back(new TreeNode(nums[begin]));
            return trees;
        }
        for (int i = begin; i < end; ++i) {
            
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
