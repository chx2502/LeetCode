//
//  main.cpp
//  LeetCode_380
//
//  Created by chx on 2020/9/22.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
/*
 核心思路：
 用一个 array 来存放所有在集合内的数字，并用随机下标来实现 getRandom()
 用一个 map 来存放集合内的数字以及它们在 array 里的下标
 用 size 记录集合的规模
 
 int insert(val):
 若 map 中已存在 val 则插入失败。
 否则，在 array 尾部增加一个 val, 对应下标为 size, size 增加 1。
 
 int remove(val):
 若 map 中不存在 val 则删除失败。
 否则，获取 val 在 array 中的下标 index，将 array 末尾的元素即 array[size-1] 挪到 index 位置，更新 map 中的下标为 -1，size 减少 1。
 
 int getRandom():
 rand() % size 返回一个 [0, size) 区间内的随机数。
 **/
class RandomizedSet {
private:
    unordered_map<int, int> data;
    vector<int> array;
    int size;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (data.count(val) && data[val] != -1) return false;
        if (size == array.size()) array.push_back(0);
        array[size] = val;
        data[val] = size;
        size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!data.count(val) || data[val] == -1) return false;
        int index = data[val];
        size--;
        int temp = array[size];
        array[index] = temp;
        data[temp] = index;
        data[val] = -1;
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return array[rand() % size];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
