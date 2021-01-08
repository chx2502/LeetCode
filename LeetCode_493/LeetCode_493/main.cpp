//
//  main.cpp
//  LeetCode_493
//
//  Created by chx on 2020/11/28.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int result;
public:
    int reversePairs(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 0) return 0;
        result = 0;
        mergeSort(nums, 0, size-1);
        return result;
    }
    void mergeSort(vector<int>& nums, int begin, int end) {
        if (begin >= end) return;
        int mid = begin + ((end-begin) >> 1);
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid+1, end);
        int i = begin;
        int j = mid+1;
        while (i <= mid && j <= end) {
            long long threshold = (long long)nums[j] * 2;
            while(i <= mid && nums[i] <= threshold) i++;
            result += mid - i + 1;
            j++;
        }
        int p = begin;
        int q = mid+1;
        vector<int> temp;
        while(p <= mid && q <= end) {
            if (nums[p] <= nums[q]) {
                temp.push_back(nums[p]);
                p++;
            } else {
                temp.push_back(nums[q]);
                q++;
            }
        }
        while(p <= mid) temp.push_back(nums[p++]);
        while(q <= end) temp.push_back(nums[q++]);
        for (int k = begin; k <= end; k++) nums[k] = temp[k-begin];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1, 3, 2, 3, 1};
    int result = s.reversePairs(nums);
    return 0;
}
