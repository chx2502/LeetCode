//
//  main.cpp
//  LeetCode_877_石子游戏
//
//  Created by chx on 2019/12/6.
//  Copyright © 2019 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct status {
        int first;
        int second;
        status(int fir=0, int sec=0): first(fir), second(sec) {}
//        void print_tuple() {
//            cout << "(" << this->first << ", " << this->second << ")";
//        }
    };
    
//    void print_matrix(vector<vector<status*>>& matrix) {
//        const unsigned long length = matrix.size();
//        for (int i = 0; i < length; i++) {
//            for (int j = 0; j < length; j++) {
//                matrix[i][j]->print_tuple();
//                cout << " ";
//            }
//            cout << endl;
//        }
//    }
    /*
     题解：https://mp.weixin.qq.com/s/_d1Y7g1jnj7VFSxbo9YWSw
     **/
    bool stoneGame(vector<int>& piles) {
        // 将数组长度读出来，保存为本地变量，减少对 size 函数的调用
        const unsigned long length = piles.size();
        vector<vector<status*>> status_matrix(length);
        // 初始化状态矩阵
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (i == j) status_matrix[i].push_back(new status(piles[i], 0));
                else status_matrix[i].push_back(new status());
            }
        }
        // 更新状态矩阵：k 为更新位置的行列号之差
        for (int k = 1; k < length; k++) {
            // start，end 分别为当前博弈数组的起点和终点（详见题解）
            for (int start = 0; start < length-k; start++) {
                int end = start + k;
                int left = piles[start] + status_matrix[start+1][end]->second;
                int right = piles[end] + status_matrix[start][end-1]->second;
                status *game_status = status_matrix[start][end];
                if (left > right) {
                    game_status->first = left;
                    game_status->second = status_matrix[start+1][end]->first;
                } else {
                    game_status->first = right;
                    game_status->second = status_matrix[start][end-1]->first;
                }
            }
        };
//        print_matrix(status_matrix);
        return status_matrix[0][length-1]->first > status_matrix[0][length-1]->second;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> piles = {5, 3, 4, 5};
    s.stoneGame(piles);
    return 0;
}
