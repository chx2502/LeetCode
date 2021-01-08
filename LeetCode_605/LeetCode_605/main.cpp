//
//  main.cpp
//  LeetCode_605
//
//  Created by chx on 2021/1/1.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = (int)flowerbed.size();
        for (int i = 0; i < size && n ;i++) {
            if (flowerbed[i]) continue;
            if (i > 0 && i < size-1) {
                if (flowerbed[i] == 0 && !(flowerbed[i-1] || flowerbed[i+1])) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            if (i == 0) {
                if (size == 1) n--;
                else if (flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            if (i == size-1 && size != 1) {
                if (flowerbed[i-1] == 0) n--;
            }
        }
        return n <= 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> flowerbed = {0, 0, 1, 0, 0};
    bool result = s.canPlaceFlowers(flowerbed, 1);
    return 0;
}
