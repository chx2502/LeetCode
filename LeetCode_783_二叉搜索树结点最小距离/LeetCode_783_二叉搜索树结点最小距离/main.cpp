//
//  main.cpp
//  LeeCode_783_二叉搜索树结点最小距离
//
//  Created by chx on 2019/10/22.
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

#define MAX 0x7FFFFFFF
class Solution {
public:
    /*
     核心思路：输入的树位二叉搜索树，其中序遍历即为由小到大的顺序数组，遍历该顺序数组找到两个相邻数最小的差值即可。
     */
    vector<int> inorder_arr;
    
    void inorder_traversal(TreeNode *root) {
        if (!root) return;
        if (root->left) inorder_traversal(root->left);
        inorder_arr.push_back(root->val);
        if (root->right) inorder_traversal(root->right);
        return;
    }
    
    int minDiffInBST(TreeNode* root) {
        inorder_traversal(root);
        int length = (int)inorder_arr.size();
        int i, j, min;
        i = 0;
        j = 1;
        min = MAX;
        while(j < length) {
            int diff_val = abs(inorder_arr[i] - inorder_arr[j]);
            if (diff_val < min) min = diff_val;
            i++;
            j++;
        }
        return min;
    }
};

int main(int argc, const char * argv[]) {
    cout << (int)(MAX+1) << endl;
    return 0;
}
