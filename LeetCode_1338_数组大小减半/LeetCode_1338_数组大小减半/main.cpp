//
//  main.cpp
//  LeetCode_1338_数组大小减半
//
//  Created by chx on 2020/3/12.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     用 map 以 <key=num, value=times> 记录所有数字出现的次数
     让后将 map 中的元素按出现次数 value 降序生成数组
     依次访问数组元素并计算累计出现次数直到 >= size/2，返回访问次数 result。
     **/
    void sortMapByValue(map<int, int> M, vector<pair<int, int>> &result) {
        for (auto iter = M.begin(); iter != M.end(); ++iter)
            result.push_back(make_pair(iter->first, iter->second));
        sort(
             result.begin(),
             result.end(),
             [](const pair<int, int> a, const pair<int, int> b) { return a.second > b.second; }
             );
    }
    
    int minSetSize(vector<int>& arr) {
        int size = (int)arr.size();
        if (size == 0) return 0;
        if (size % 2) size += 1;
        size /= 2;
        map<int, int> M;
        
        for (auto &num : arr) M[num]++;
        int count = 0;
        vector<pair<int, int>> vec;
        sortMapByValue(M, vec);
        int result = 0;
        for (auto &item : vec) {
            if (count < size) {
                count += item.second;
                result++;
            }
            if (count >= size) break;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
