//
//  main.cpp
//  LeetCode_427_建立四叉树
//
//  Created by chx on 2020/3/4.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* helper(vector<vector<int>>& grid, int row, int col, int N) {
        int first = grid[row][col];
        Node *result = new Node();
        bool isLeaf = true;
        int m, n;
        m = row+N;
        n = col+N;
        for (int i = row; i < m; ++i)
            for (int j = col; j < n; ++j)
                if (grid[i][j] != first) isLeaf = false;
        if (isLeaf) {
            result->val = first;
            result->isLeaf = isLeaf;
        } else {
            N /= 2;
            result->isLeaf = isLeaf;
            result->topLeft = helper(grid, row, col, N);
            result->topRight = helper(grid, row, col+N, N);
            result->bottomLeft = helper(grid, row+N, col, N);
            result->bottomRight = helper(grid, row+N, col+N, N);
        }
        return result;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int N = (int)grid.size();
        if (N == 0) return NULL;
        return helper(grid, 0, 0, N);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
