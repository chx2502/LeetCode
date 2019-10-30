//
//  main.cpp
//  LeetCode_11_盛水最多的容器
//
//  Created by chx on 2019/10/27.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     数组首尾之间各放一个指针，两者中较小的那个为容器高度，两者间距离为容器宽度
     容积 = 宽度 * 高度
     每计算完一次容积，高度较小的指针向另一指针所在方向移动，同时视情况更新 max_capacity
     结束条件：两指针相遇
     */
    int min(int a, int b) { return a < b ? a : b; }
    int maxArea(vector<int>& height) {
        unsigned long length = height.size();
        if (length < 2) return 0;
        int i, j;
        i = 0;
        j = (int)length - 1;
        int max_capacity = 0;
        while(i < j) {
            int distance = j - i;
            int capacity = min(height[i], height[j]) * distance;
            if (capacity > max_capacity)
                max_capacity = capacity;
//            if (height[i] < height[j]) {
//                int temp = height[i];
//                while (height[i] <= temp && i < j)
//                    i++;
//            } else {
//                int temp = height[j];
//                while (height[j] <= temp && j > i)
//                    j--;
//            }
            if (height[i] < height[j])
                i++;
            else j--;
        }
        return max_capacity;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
