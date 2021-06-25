#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> indexStk;
        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        unsigned long size = heights.size();
        int result = 0;
        for (int i = 0; i < size; i++) {
            while (!indexStk.empty() && heights[indexStk.top()] > heights[i]) {
                int curr = indexStk.top();
                indexStk.pop();
                int left = indexStk.top()+1;
                int right = i-1;
                int h = heights[curr];
                result = max(result, h * (right-left+1));
            }
            indexStk.push(i);
        }
        return result;
    }
};
