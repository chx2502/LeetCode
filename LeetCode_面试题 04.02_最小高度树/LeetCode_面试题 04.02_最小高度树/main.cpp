//
//  main.cpp
//  LeetCode_面试题 04.02_最小高度树
//
//  Created by chx on 2020/4/17.
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
    TreeNode* createBST(int begin, int end, vector<int>& sortedArray) {
        if (begin > end) return nullptr;
        int mid = (begin + end) / 2;
        TreeNode *node = new TreeNode(sortedArray[mid]);
        node->left = createBST(begin, mid-1, sortedArray);
        node->right = createBST(mid+1, end, sortedArray);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) return nullptr;
        return createBST(0, size-1, nums);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
