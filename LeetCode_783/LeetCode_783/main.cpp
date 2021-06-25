//
//  main.cpp
//  LeetCode_783
//
//  Created by chx on 2021/4/13.
//

#include <iostream>
#include <queue>
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
    int mostRight(TreeNode *root) {
        if (!root) return 0;
        TreeNode *p = root;
        while (p && p->right) p = p->right;
        return p->val;
    }
    
    int mostLeft(TreeNode *root) {
        if (!root) return 0;
        TreeNode *p = root;
        while (p && p->left) p = p->left;
        return p->val;
    }
    
    int minDiffInBST(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int result = INT_MAX;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left) {
                result = min(result, node->val - mostRight(node->left));
                q.push(node->left);
            }
            if (node->right) {
                result = min(result, mostLeft(node->right) - node->val);
                q.push(node->right);
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
