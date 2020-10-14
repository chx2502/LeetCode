//
//  main.cpp
//  LeetCode_530
//
//  Created by chx on 2020/10/12.
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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        while (p || !stk.empty()) {
            while (p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            result.push_back(p->val);
            p = p->right;
        }
        return result;
    }
    
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        vector<int> array = inorderTraversal(root);
        int p, q;
        p = 0; q = 1;
        int result = INT_MAX;
        while (q < array.size()) result = min(result, array[q++]-array[p++]);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
