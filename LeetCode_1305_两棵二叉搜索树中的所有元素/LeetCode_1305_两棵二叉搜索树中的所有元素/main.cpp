//
//  main.cpp
//  LeetCode_1305_两棵二叉搜索树中的所有元素
//
//  Created by chx on 2020/2/23.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

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
     中序遍历两个二叉搜索树，分别保存于两个数组，然后合并两个有序数组
     **/
    vector<int> inorder(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> S;
        TreeNode *p = root;

        while (!S.empty() || p) {
            if (p) {
                S.push(p);
                p = p->left;
            } else {
                p = S.top();
                S.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr_1;
        vector<int> arr_2;
        vector<int> result;
        
        arr_1 = inorder(root1);
        arr_2 = inorder(root2);
        
        int size1, size2;
        int i, j;
        size1 = (int)arr_1.size();
        size2 = (int)arr_2.size();
        i = j = 0;
        
        while (i < size1 && j < size2) {
            int temp = arr_1[i] < arr_2[j] ? arr_1[i++] : arr_2[j++];
            result.push_back(temp);
        }
        
        while (i < size1) result.push_back(arr_1[i++]);
        while (j < size2) result.push_back(arr_2[j++]);
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
