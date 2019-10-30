//
//  main.cpp
//  LeetCode_88_合并两个有序数组
//
//  Created by chx on 2019/10/26.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        for (int i = 0; i < m; i++)
            temp.push_back(nums1[i]);
        int i, j;
        i = 0;
        j = 0;
        nums1.clear();
        while (i < m && j < n) {
            int t = temp[i] < nums2[j] ? temp[i++] : nums2[j++];
            nums1.push_back(t);
        }
        if (i == m)
            while (j < n)
                nums1.push_back(nums2[j++]);
        if (j == n)
            while (i < m)
                nums1.push_back(temp[i++]);
        return;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
    for (auto i : nums1)
        cout << i << endl;
    return 0;
}
