//
//  main.cpp
//  LeetCode_961_重复 N 次的元素
//
//  Created by chx on 2020/2/15.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     解法 1:
     数组当做 hash map 使用，对出现次数计数。
     **/
//    int repeatedNTimes(vector<int>& A) {
//        const int MAX = 10001;
//        const int target = (int)A.size() / 2;
//        int result = MAX;
//        vector<int> map(MAX, 0);
//        for (auto &num : A) {
//            result = num;
//            map[num] += 1;
//            if (map[num] == target) break;
//        }
//        return result;
//    }
    /*
     解法 2:
     脑筋急转弯。
     找重复， 2N 个数字中有 N 个不重复和 N 个重复，则重复的数必为解。
     **/
    int repeatedNTimes(vector<int>& A) {
        int length = (int)A.size();
        int result = -1;
        for (int k = 1; k < 4; k++)
            for (int i = 0; i < length-k; i++)
                if (A[i] == A[i+k])
                    return A[i];
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
