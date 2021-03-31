//
//  main.cpp
//  LeetCode_705
//
//  Created by chx on 2021/3/13.
//

#include <iostream>
#include <vector>
#include <random>
#include <list>

using namespace std;

class MyHashSet {
private:
    int hashSeed;
    int minSeed;
    vector<list<int>> hashTable;
    
    int genSeed(int end) {
        if (minSeed >= end) return -1;
        vector<bool>dp (end, true);
        vector<int> primes;
        for (int i = 2; i < end; i++) {
            if (i >= minSeed) primes.push_back(i);
            if (dp[i]) {
                int j = 2;
                while (i*j < end) {
                    dp[i*j] = false;
                    j++;
                }
            }
        }
        srand(2333);
        int index = rand() % primes.size();
        return primes[index];
    }
    
    int getHashValue(int key) {
        return key % hashSeed;
    }
    
    list<int>& getLinkedList(int key) {
        int hashValue = getHashValue(key);
        return hashTable[hashValue];
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        minSeed = 5000;
        hashSeed = genSeed(6000);
        hashTable.assign(hashSeed, list<int>());
    }
    
    void add(int key) {
        list<int> &ll = getLinkedList(key);
        for (auto it = ll.begin(); it != ll.end(); ++it) {
            if (*it == key) return;
        }
        ll.emplace(ll.begin(), key);
        return;
    }
    
    void remove(int key) {
        list<int> &ll = getLinkedList(key);
        ll.remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        list<int> &ll = getLinkedList(key);
        for (auto it = ll.begin(); it != ll.end(); ++it) {
            if (*it == key) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    MyHashSet s;
    s.add(1);
    bool res1 = s.contains(1);
    s.remove(1);
    bool res2 = s.contains(1);
    s.remove(1);
    bool res3 = s.contains(1);
    s.add(1000000);
    bool res4 = s.contains(1000000);
    return 0;
}
