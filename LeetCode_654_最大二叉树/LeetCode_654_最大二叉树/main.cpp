//
//  main.cpp
//  LeetCode_654_最大二叉树
//
//  Created by chx on 2019/11/7.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
     递归解法:
     在数组中找到最大数，创建根节点，
     递归地在左右两个子数组的进行这一步骤，
     左子树的根作为左孩子，右子树的根作为右孩子，
     遇到空数组返回。
     */
//    vector<int>::iterator findMax(vector<int> &nums) {
//        vector<int>::iterator i = nums.begin();
//        vector<int>::iterator ret = nums.begin();
//        int max = 0xFFFFFFFF;
//        while(i != nums.end()) {
//            if (max < *i) {
//                max = *i;
//                ret = i;
//            }
//            i++;
//        }
//        return ret;
//    }
    
//    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//        vector<int>::iterator max = findMax(nums);
//        TreeNode *root = new TreeNode(*max);
//        vector<int> left_nodes = vector<int>(nums.begin(), max);
//        vector<int> right_nodes = vector<int>(max+1, nums.end());
//
//        if (left_nodes.size()) root->left = constructMaximumBinaryTree(left_nodes);
//        if (right_nodes.size()) root->right = constructMaximumBinaryTree(right_nodes);
//        return root;
//    }
    /*
     遍历解法：
     指针指向根节点，每次新加入一个节点，就寻找其插入的位置。
     */
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *max_node = new TreeNode(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            TreeNode *root = new TreeNode(nums[i]);
            if (nums[i] > max_node->val) {
                root->left = max_node;
                max_node = root;
                continue;
            }
            TreeNode *temp = max_node;
            while (temp->right != nullptr) {
                if (temp->right->val > root->val)
                    temp = temp->right;
                else {
                    root->left = temp->right;
                    temp->right = root;
                    break;
                }
            }
            if (temp->right == nullptr) temp->right = root;
        }
        return max_node;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode *tree = s.constructMaximumBinaryTree(nums);
    
    return 0;
}
