//
//  main.cpp
//  LeetCode_968
//
//  Created by chx on 2020/9/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    const int MAX = INT_MAX / 2;
    vector<int> cover(TreeNode* root) {
        if (!root) return { MAX, 0, 0 };
        vector<int> left = cover(root->left);
        vector<int> right = cover(root->right);
        int a = left[2] + right[2] + 1;
        int b = min(a, min(left[0]+right[1], left[1]+right[0]));
        int c = min(a, left[1] + right[1]);
        return { a, b, c };
    }
    
    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        return cover(root)[1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
