//
//  main.cpp
//  108. 将有序数组转换为二叉搜索树
//
//  Created by chx on 2020/1/8.
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
    /*
     核心思路：
     找到当前树根元素，在该元素两边的子数组分别生成 BST 作为左右子树
     **/
    TreeNode* buildBST(int begin, int end, vector<int>& nums) {
        if (begin >= end) return NULL;
        int mid = (begin + end) >> 1;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildBST(begin, mid, nums);
        root->right = buildBST(mid+1, end, nums);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int length = (int)nums.size();
        if (length == 0) return NULL;
        return buildBST(0, length, nums);
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode *result = s.sortedArrayToBST(nums);
    
    return 0;
}
