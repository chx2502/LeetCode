//
//  main.cpp
//  LeetCode_167_两数之和 II - 输入有序数组
//
//  Created by 成鑫 on 2019/8/4.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //  暴力解法
//    vector<int> twoSum(vector<int>& numbers, int target) {
//        int i, j, size;
//        i = j = 0;
//        size = (int)numbers.size();
//
//        vector<int> ret;
//        if (size == 0) return ret;
//        while(i < size) {
//            if (numbers[i] > target) return ret;
//            j = i + 1;
//            while (j < size) {
//                if (numbers[i] + numbers[j] == target) {
//                    ret.push_back(i+1);
//                    ret.push_back(j+1);
//                    return ret;
//                } else j++;
//            }
//            while (numbers[i] == numbers[i+1]) i++;
//            i++;
//        }
//        return ret;
//    }
    //  非暴力解法：首尾各一个指针，两者之和大于 target 则大端左移，小于 target 小端右移。
    //  优化：每次移动指针时跳过所有相同值，知道找到下一个不同值再计算。
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = (int)numbers.size();
        int i = 0;
        int j = size-1;
        vector<int> ret;
        
        while(i < j) {
            if (numbers[i] + numbers[j] < target) {
                while (numbers[i] == numbers[i+1]) i++;
                i++;
            } else if (numbers[i] + numbers[j] > target) {
                while (numbers[j] == numbers[j-1]) j--;
                j--;
            } else {
                ret.push_back(i+1);
                ret.push_back(j+1);
                return ret;
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
