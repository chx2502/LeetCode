//
//  main.cpp
//  LeetCode_706
//
//  Created by chx on 2021/3/14.
//

#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class MyHashMap {
private:
    int hashSeed;
    int minSeed;
    vector<list<pair<int, int>>> hashTable;
    
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
    
    list<pair<int, int>>& getLinkedList(int key) {
        int hashValue = getHashValue(key);
        return hashTable[hashValue];
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        minSeed = 233;
        hashSeed = genSeed(2333);
        hashTable.assign(hashSeed, list<pair<int, int>>());
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        list<pair<int, int>>& ll = getLinkedList(key);
        for (auto it = ll.begin(); it != ll.end(); ++it) {
            if ((*it).first == key) {
                (*it).second = value;
                return;
            }
        }
        ll.emplace(ll.begin(), pair<int, int>(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        list<pair<int, int>>& ll = getLinkedList(key);
        for (auto it = ll.begin(); it != ll.end(); ++it) {
            if ((*it).first == key) return (*it).second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        list<pair<int, int>> ll = getLinkedList(key);
        for (auto it = ll.begin(); it != ll.end(); ++it) {
            if ((*it).first == key) {
                ll.erase(it);
                return;
            }
        }
    }
};



int main(int argc, const char * argv[]) {
    MyHashMap hashMap = MyHashMap();
    hashMap.put(1, 1);
    int res1 = hashMap.get(1);
    
    return 0;
}
