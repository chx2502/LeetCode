//
//  main.cpp
//  LeetCode_面试16.25
//
//  Created by chx on 2021/3/2.
//

#include <iostream>
#include <vector>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> linkedHashmap;
    list<pair<int, int>> cache;
    int capacity;
    int size;
    
    void insertNewCache(int key, int value) {
        cache.emplace(cache.begin(), pair<int, int>(key, value));
        linkedHashmap[key] = cache.begin();
    }
    
    void deleteCache(int key) {
        cache.erase(linkedHashmap[key]);
        linkedHashmap.erase(key);
    }
    
    void updateCache(int key, int value) {
        cache.erase(linkedHashmap[key]);
        insertNewCache(key, value);
    }
    
    void moveToFront(int key) {
        int value = (*linkedHashmap[key]).second;
        deleteCache(key);
        insertNewCache(key, value);
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        auto it = linkedHashmap.find(key);
        if (it == linkedHashmap.end()) {
            return -1;
        } else {
            moveToFront(key);
        }
        return cache.begin()->second;
    }
    
    void put(int key, int value) {
        auto it = linkedHashmap.find(key);
        if (it == linkedHashmap.end()) {
            if (size < capacity) {
                insertNewCache(key, value);
                size++;
            } else {
                deleteCache(cache.back().first);
                insertNewCache(key, value);
            }
        } else {
            updateCache(key, value);
        }
    }
};

int main(int argc, const char * argv[]) {
    LRUCache lru(2);
    lru.put(2, 1);
    lru.put(2, 2);
    int res1 = lru.get(2);
    lru.put(1, 1);
//    int res2 = lru.get(2);
    lru.put(4, 1);
    int res3 = lru.get(2);
//    int res4 = lru.get(3);
//    int res5 = lru.get(4);
    return 0;
}
