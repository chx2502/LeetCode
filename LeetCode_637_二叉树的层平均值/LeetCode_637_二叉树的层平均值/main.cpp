//
//  main.cpp
//  LeetCode_637_二叉树的层平均值
//
//  Created by 成鑫 on 2019/7/18.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
     vector<double> averageOfLevels(TreeNode* root) {
         queue<TreeNode*> q1, q2;
         vector<double> res;
        
         if (!root) return res;
         q1.push(root);
         do {
             double sum = 0;
             int width = 0;
             while (!q1.empty()) {
                 TreeNode *node = q1.front();
                 q1.pop();
                 q2.push(node);
             }
             while (!q2.empty()) {
                 TreeNode *node = q2.front();
                 q2.pop();
                 if (node->left) q1.push(node->left);
                 if (node->right) q1.push(node->right);
                 width += 1;
                 sum += node->val;
             }
             res.push_back(sum / width);
         } while (!q1.empty());
         return res;
     }
//    unordered_map<int, double> level_map;
//    unordered_map<int, int> level_count;
//    int total_level = -1;
//    void dfs(TreeNode* root, int level) {
//        if (!root) return;
//        level_count[level] += 1;
//        if (level_map.find(level) == level_map.end())
//            level_map[level] = root->val;
//        else level_map[level] += root->val;
//        total_level = max(total_level, level);
//        dfs(root->left, level+1);
//        dfs(root->right, level+1);
//    }
//    vector<double> averageOfLevels(TreeNode* root) {
//        dfs(root, 0);
//        vector<double> result(total_level+1, 0.0);
//        for (auto item : level_map) {
//            int level = item.first;
//            double sum = item.second;
//            result[level] = sum / 1.0 / level_count[level];
//        }
//        return result;
//    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    double result = 0.0 / 2 + 2.0 / 2;
    cout << result << endl;
    return 0;
}
