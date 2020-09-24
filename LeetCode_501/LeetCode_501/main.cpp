//
//  main.cpp
//  LeetCode_501
//
//  Created by chx on 2020/9/24.
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
    int max_count, pre, count;
    vector<int> result;
    void inTraversal(TreeNode* root) {
        if (!root) return;
        inTraversal(root->left);
        if (root->val == pre) {
            count++;
            if (count == max_count) {
                result.push_back(pre);
            }
            if (count > max_count) {
                result.clear();
                result.push_back(pre);
                max_count = count;
            }
        } else {
            count = 1;
            if (count == max_count) result.push_back(root->val);
            pre = root->val;
        }
        inTraversal(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        if (!root) return result;
        max_count = 1;
        pre = root->val/2;
        inTraversal(root);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
