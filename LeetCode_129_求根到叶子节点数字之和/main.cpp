#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
    /*
     * 参考题解：
     * https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/solution/0-ms-jiao-ke-shu-ji-jie-da-by-liuzhaoce/
     * https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/solution/dfs-by-user2473e/
     * 我太菜了。
     */

//    int helper(TreeNode *root, int father) {
//        if (!root) return 0;
//        int temp = father * 10 + root->val;
//        if (root->left == nullptr && root->right == nullptr) return temp;
//        return helper(root->left, temp) + helper(root->right, temp);
//    }

    void dfs(TreeNode *root, int father, int& result) {
        if (!root) return;
        father = father*10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            result += father;
            return;
        }
        dfs(root->left, father, result);
        dfs(root->right, father, result);
    }

    int sumNumbers(TreeNode* root) {
//        return helper(root, 0);
        int result = 0;
        dfs(root, 0, result);
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
