//
//  main.cpp
//  LeetCode_1104_二叉树寻路
//
//  Created by chx on 2020/3/11.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    /*
     很慢的解法
     思路：根据规律构造 ZagTree，然后根据数组下标获取路径。
     **/
    vector<int> pathInZigZagTree(int label) {
        vector<int> zag_tree = buildZagTree(label*2);
        int index = 0;
        while (zag_tree[index] != label) index++;
        vector<int> result;
        while (index > 0) {
            result.push_back(zag_tree[index]);
            index /= 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    vector<int> buildZagTree(int N) {
        vector<int> zag_tree;
        zag_tree.push_back(0);
        int level = 1;
        int i = 1;
        while (i <= N) {
            int count = pow(2, level-1);
            if (level % 2 == 0) {
                int begin = i + count -1;
                while (count) {
                    zag_tree.push_back(begin--);
                    i++;
                    if (i > N) break;
                    count--;
                }
            } else {
                while (count) {
                    zag_tree.push_back(i++);
                    if (i > N) break;
                    count--;
                }
            }
            level++;
        }
        return zag_tree;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> res = s.pathInZigZagTree(2);
    return 0;
}
