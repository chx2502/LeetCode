//
//  main.cpp
//  LeetCode_1282_用户分组
//
//  Created by chx on 2020/2/27.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     建立一个以 <size, vector<int>> 的 map
     首先将属于各种 size 的 ID（即 groupSizes 的数组下标）以 size 为 key 加入到相应的数组中
     每种 size 的 ID 需要 n=(ID 总数量 / size) 个数组来存储，于是生成一个 n * size 维数组 temp
     然后对于 map 中每一种 size 对应的 vector 进行遍历， 每存储 size 个元素就存入到 temp 的下一个数组
     把所有 temp 中的s数组压入返回结果 result 中，直到遍历完 map 中的所有 size 值
     **/
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int length = (int)groupSizes.size();
        map<int, vector<int>> M;
        vector<int> groupSize;
        vector<vector<int>> result;
        
        for (int i = 0; i < length; ++i) M[groupSizes[i]].push_back(i);
        for (auto iter = M.begin(); iter != M.end(); ++iter) {
            int size = iter->first;
            vector<int> storage = iter->second;
            vector<vector<int>> temp(storage.size() / size);
            int i = 0;
            for (int &num : storage) {
                if (temp[i].size() != size)
                    temp[i].push_back(num);
                else temp[++i].push_back(num);
            }
            for (auto &array : temp) result.push_back(array);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> groupSizes = {3, 3, 3, 3, 3, 1, 3};
    vector<vector<int>> result = s.groupThePeople(groupSizes);
    return 0;
}
