//
//  main.cpp
//  LeetCode_275_H指数 II
//
//  Created by 成鑫 on 2019/1/10.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    // 核心思想是二分查找，注意处理全0或全1的边界条件和空数组的情况。
    int hIndex(vector<int>& citations) {
        int end = int(citations.size());
        int left = 0;
        int right = end - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (citations[mid] == end - mid) return end - mid;
            if (citations[mid] > end - mid - 1) {
                right = mid - 1;
            } else left = mid + 1;
        }
        return end - left;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> v = {1, 1};
    Solution s;
    cout << s.hIndex(v) << endl;
    return 0;
}
