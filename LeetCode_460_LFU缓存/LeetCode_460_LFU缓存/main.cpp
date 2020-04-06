//
//  main.cpp
//  LeetCode_460_LFU缓存
//
//  Created by chx on 2020/4/5.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;



class LFUCache {
private:
    
    struct Node {
        int key;
        int value;
        int frequency;
        Node(int k, int v, int f): key(k), value(v), frequency(f) {}
    };
    
    int capacity;
    int minfreq;
    unordered_map<int, list<Node>::iterator> value_map;
    unordered_map<int, list<Node>> freq_map;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minfreq = 0;
        value_map.clear();
        freq_map.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto temp = value_map.find(key);
        if (temp == value_map.end()) return -1;
        list<Node>::iterator node = temp->second;
        int val = node->value;
        int freq = node->frequency;
        freq_map[freq].erase(node);
        
        if (freq_map[freq].size() == 0) {
            freq_map.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        freq_map[freq+1].push_front(Node(key, val, freq+1));
        value_map[key] = freq_map[freq+1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto temp = value_map.find(key);
        if (temp == value_map.end()) {
            if (value_map.size() == capacity) {
                auto oldest = freq_map[minfreq].back();
                value_map.erase(oldest.key);
                freq_map[minfreq].pop_back();
                if (freq_map[minfreq].size() == 0)
                    freq_map.erase(minfreq);
            }
            freq_map[1].push_front(Node(key, value, 1));
            value_map[key] = freq_map[1].begin();
            minfreq = 1;
        } else {
            list<Node>::iterator node = temp->second;
            int freq = node->frequency;
            freq_map[freq].erase(node);
            if (freq_map[freq].size() == 0) {
                freq_map.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_map[freq+1].push_front(Node(key, value, freq+1));
            value_map[key] = freq_map[freq+1].begin();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
