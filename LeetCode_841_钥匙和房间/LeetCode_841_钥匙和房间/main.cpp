//
//  main.cpp
//  LeetCode_841_钥匙和房间
//
//  Created by 成鑫 on 2019/1/9.
//  Copyright © 2019 成鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int visited = 0;
        queue<int> my_queue;
        vector<int> accessible(rooms.size(), 0);
        my_queue.push(visited);
        do {
            visited = my_queue.front();
            accessible[visited] = 1;
            vector<int> temp = rooms[visited];
            for (int i = 0; i < temp.size(); ++i) {
                if (accessible[temp[i]] != 1) {
                    my_queue.push(temp[i]);
                }
            }
            my_queue.pop();
        } while (my_queue.size());
        for (int i = 0; i < accessible.size(); ++i) {
            if (accessible[i] == 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
