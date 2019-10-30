//
//  main.cpp
//  LeetCode_350_两个数组的交集 II
//
//  Created by chx on 2019/10/26.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if (nums1.size() == 0 || nums2.size() == 0) return ret;
        map<int, int> count_map;
        for (auto i : nums1) {
            if (count_map.find(i) == count_map.end())
                count_map[i] = 0;
            count_map[i] += 1;
        }
        for (auto i : nums2) {
            map<int, int>::iterator iter = count_map.find(i);
            if (iter == count_map.end())
                continue;
            else {
                if (iter->second == 0) continue;
                else {
                    ret.push_back(i);
                    iter->second -= 1;
                }
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
