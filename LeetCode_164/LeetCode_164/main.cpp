//
//  main.cpp
//  LeetCode_164
//
//  Created by chx on 2020/11/26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = (int)nums.size();
        if (size < 2) return 0;
        
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        int d = max(1, (maxNum - minNum) / (size - 1));
        int bucketSize = (maxNum - minNum) / d + 1;
        
        vector<pair<int, int>> bucketArray(bucketSize, {-1, -1});
        for (int i = 0; i < size; i++) {
            int index = (nums[i] - minNum) / d;
            if (bucketArray[index].first == -1) {
                bucketArray[index].first = bucketArray[index].second = nums[i];
            } else {
                bucketArray[index].first = min(nums[i], bucketArray[index].first);
                bucketArray[index].second = max(nums[i], bucketArray[index].second);
            }
        }
        int result = 0;
        int pre = 0;
        for (int i = 1; i < bucketSize; i++) {
            if (bucketArray[i].first == -1) continue;
            result = max(result, bucketArray[i].first - bucketArray[pre].second);
            pre = i;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
