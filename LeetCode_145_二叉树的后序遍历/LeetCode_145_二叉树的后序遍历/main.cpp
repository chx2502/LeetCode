//
//  main.cpp
//  LeetCode_145_二叉树的后序遍历
//
//  Created by chx on 2019/10/24.
//  Copyright © 2019 成鑫. All rights reserved.
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
     二叉树后序遍历，非递归实现
     核心思路：
     利用栈实现，根节点先入栈，当栈非空时，弹出元素进入返回列表，同时左右孩子依次入栈。
     最后得到的返回列表为后序遍历的逆序，若入列时采用头插法，则可以免去 reverse 操作, 减少用时。
     */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode *top = stk.top();
            stk.pop();
            ret.insert(ret.begin(), top->val);
            if (top->left) stk.push(top->left);
            if (top->right) stk.push(top->right);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
