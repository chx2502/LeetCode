//
//  main.cpp
//  LeetCode_513_找树左下角的值
//
//  Created by chx on 2019/10/29.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> array) {
    if (array.size() == 0) return NULL;
    vector<TreeNode*> nodes;
    TreeNode *dump = new TreeNode(0xFFFFFFFF);
    nodes.push_back(dump);
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == INT32_MIN) {
            nodes.push_back(NULL);
            continue;
        }
        TreeNode *node = new TreeNode(array[i]);
        nodes.push_back(node);
    }
    for (int i = 1; i < nodes.size(); i++) {
        TreeNode *temp = nodes[i];
        if (!temp) continue;
        if (i*2 < nodes.size()) temp->left = nodes[i*2];
        if (i*2 + 1 < nodes.size()) temp->right = nodes[i*2 + 1];
    }
    return nodes[1];
}

class Solution {
public:
    /*
     核心思路：
     层序遍历，输出最后一层第一个数。
     DFS 也可以做，但当时没想明白。
     */
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return -1;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        do {
            vector<TreeNode*> level;
            while (!node_queue.empty()) {
                TreeNode *node = node_queue.front();
                node_queue.pop();
                level.push_back(node);
            }
            for (auto node : level) {
                if (node->left) node_queue.push(node->left);
                if (node->right) node_queue.push(node->right);
            }
            if (node_queue.empty()) return level[0]->val;
        } while(!node_queue.empty());
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> array = {1, 2, 3, 4, INT32_MIN, 5, 6, INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN, 7};
    vector<int> array2 = {2, 1, 3};
    TreeNode *tree = buildTree(array);
    Solution s;
    int result = s.findBottomLeftValue(tree);
    cout << result << endl;
    return 0;
}
