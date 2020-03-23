#include <iostream>
#include <queue>
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
    void inOrderTraverse (TreeNode *root, vector<int>& array, int k) {
        if (!root) return;
        // 只要第 k 大，因此遍历到第 k 个就可以结束了。
        if (array.size() == k) return;
        inOrderTraverse(root->right, array, k);
        array.push_back(root->val);
        inOrderTraverse(root->left, array, k);
        return;
    }
    int kthLargest(TreeNode* root, int k) {
        if (!root) return 0;
        vector<int> array;
        inOrderTraverse(root, array, k);
        return array[k-1];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
