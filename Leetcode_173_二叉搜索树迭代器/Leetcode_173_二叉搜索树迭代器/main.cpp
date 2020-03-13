//
//  main.cpp
//  Leetcode_173_二叉搜索树迭代器
//
//  Created by chx on 2020/3/13.
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

class BSTIterator {
public:
    
    stack<TreeNode*> S;
    
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *top = S.top();
        S.pop();
        if (top->right) helper(top->right);
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !S.empty();
    }
    
private:
    void helper(TreeNode *root) {
        TreeNode *p = root;
        while (p) {
            S.push(p);
            p = p->left;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
