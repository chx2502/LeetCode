//
//  main.cpp
//  LeetCode_239
//
//  Created by chx on 2021/1/2.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    struct numElement {
        int num;
        int index;
        numElement(int n, int i): num(n), index(i) {};
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = (int)nums.size();
        if (size == 0) return {};
        auto cmp = [](numElement& a, numElement& b) {
            if (a.num == b.num) return a.index < b.index;
            else return a.num < b.num;
        };
        vector<int> result;
        priority_queue<numElement, vector<numElement>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < k; i++) pq.push(numElement(nums[i], i));
        result.push_back(pq.top().num);
        for (int i = k; i < size; i++) {
            pq.push(numElement(nums[i], i));
            while (pq.top().index <= i-k) pq.pop();
            result.push_back(pq.top().num);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = { 4, -2 };
    int k = 2;
    Solution s;
    vector<int> result = s.maxSlidingWindow(nums, k);
    return 0;
}
