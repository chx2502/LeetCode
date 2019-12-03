//
//  main.cpp
//  LeetCode_832_翻转图像
//
//  Created by chx on 2019/11/30.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     核心思路：
     双指针分别指向两个需要交换位置的元素，元素相同则二者取反，相异则不变
     指针相遇时说明此位不翻转，直接取反。
     */
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto &array : A) {
            int length = (int)array.size();
            int i, j;
            i = 0;
            j = length - 1;
            while(i <= j) {
                if (array[i] == array[j])
                    array[i] = array[j] = 1 - array[i];
                i++;
                j--;
            }
        }
        return A;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> A = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    s.flipAndInvertImage(A);
    return 0;
}
