#include <iostream>
#include <queue>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:
    int xParent, yParent, xLevel, yLevel;
    void levelTraverse(TreeNode *root, int x, int y) {
        if (!root) return;
        queue<TreeNode*> q;
        queue<TreeNode*> buffer;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            if (xParent >= 0 && yParent >= 0 && xLevel >= 0 && yLevel >= 0) break;
            while (!q.empty()) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->val == x) xLevel = level;
                if (curr->val == y) yLevel = level;
                if (curr->left) {
                    if (curr->left->val == x) xParent = curr->val;
                    if (curr->left->val == y) yParent = curr->val;
                    buffer.push(curr->left);
                }
                if (curr->right) {
                    if (curr->right->val == x) xParent = curr->val;
                    if (curr->right->val == y) yParent = curr->val;
                    buffer.push(curr->right);          
                }                
            }
            while (!buffer.empty()) {
                q.push(buffer.front());
                buffer.pop();
            }
            level++;
        }
        return;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        xParent = yParent = xLevel = yLevel = -1;
        levelTraverse(root, x, y);
        // cout << "xLevel: " << xLevel << " yLevel" << yLevel << endl;
        // cout << "xParent: " << xParent << " yParent:" << yParent << endl; 
        return (xLevel == yLevel) && (xParent != yParent);
    }
};