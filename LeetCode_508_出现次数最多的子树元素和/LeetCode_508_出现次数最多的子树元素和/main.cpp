//
//  main.cpp
//  LeetCode_508_出现次数最多的子树元素和
//
//  Created by chx on 2020/2/17.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

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
     当前树的元素和 = 根节点元素 + 左子树和 + 右子树和
     用 map 记录所有子树和，将其中出现次数最多的和值加入返回结果
     **/
    int subTreeSum(TreeNode *root, unordered_map<int, int>& M) {
        if (!root) return 0;
        int sum = root->val + subTreeSum(root->left, M) + subTreeSum(root->right, M);
        M[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> M;
        vector<int> result;
        subTreeSum(root, M);
        int max = INT_MIN;
        for (auto item : M) {
            if (max < item.second)
                max = item.second;
        }
        for (auto item : M) {
            if (item.second == max)
                result.push_back(item.first);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode *node = new TreeNode(1);
    Solution s;
    vector<int> result = s.findFrequentTreeSum(node);
    return 0;
}
