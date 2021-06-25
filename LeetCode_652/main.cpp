#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

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
    int index;
    vector<TreeNode*> answer;
    unordered_map<string, int> tree2index;
    unordered_map<int, int> index2count;
    string dfs(TreeNode *root) {
        if (!root) return "#";
        string result = to_string(root->val) + "*" + dfs(root->left) + "*"+ dfs(root->right);
        auto it = tree2index.find(result);
        if (it == tree2index.end()) {
            tree2index[result] = index;
            index2count[index] = 1;
            index++;
        } else {
            if (index2count[it->second] == 1) answer.push_back(root);
            index2count[it->second]++;
        }
        return result;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        index = 0;
        dfs(root);
        return answer;
    }
};