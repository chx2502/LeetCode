//
//  main.cpp
//  LeetCode_355_设计推特
//
//  Created by chx on 2020/4/13.
//  Copyright © 2020 __Ninja__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Twitter {
private:
    struct Tweet {
        int uid;
        int id;
        int time;
        Tweet(int _uid, int _id, int _time) : uid(_uid), id(_id), time(_time) {}
    };
    /**
     users 保存现有用户 id
     follow_map 维护所有用户的关注情况，每个用户的关注列表为一个集合，键值为用户 id
     tweet_map 维护所有用户的 tweet，每个用户的 tweet 列表为一个双端队列，键值为用户 id
     */
    unordered_set<int> users;
    unordered_map<int, unordered_set<int>> follow_map;
    unordered_map<int, deque<Tweet>> tweet_map;
    int curr_time;
    const int FEEDNUM = 10;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        curr_time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        // userId 不存在则新建一个用户
        if (users.find(userId) == users.end()) users.insert(userId);
        // 发推的同时要更新 curr_time，curr_time 越大表示发推时间越晚
        Tweet t(userId, tweetId, curr_time++);
        tweet_map[userId].push_front(t);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        // userId 不存在则返回空。
        if (users.find(userId) == users.end()) return result;
        
        // 维护有推文的用户的 id
        vector<int> user_array;
        // 维护对应用户的 Tweet 队列起始查看位置
        vector<int> index_array;
        
        // 若本用户发过 tweet，将本用户的推文队列加入候选
        if (!tweet_map[userId].empty()) {
            index_array.push_back(0);
            user_array.push_back(userId);
        }
        // 在本用户的关注的用户中，将发过 tweet 的加入候选
        for (auto &id : follow_map[userId]) {
            if (tweet_map[id].empty()) continue;
            index_array.push_back(0);
            user_array.push_back(id);
        }
        bool all_empty = index_array.empty();
        int count = 0;
        int size = (int)user_array.size();
        
        // 多路归并，按发 tweet 的时间从大到小来选择，最多选择 FEEDNUM 个
        while (!all_empty && count < FEEDNUM) {
            int latest = -1;
            int select = -1;
            
            for (int i = 0; i < size; ++i) {
                int id = user_array[i];
                int index = index_array[i];
                if (index >= tweet_map[id].size()) continue;
                Tweet *t = &tweet_map[id][index];
                if (latest < t->time) {
                    select = i;
                    latest = t->time;
                }
            }
            // select == -1 说明未选中任何用户
            if (select != -1) {
                Tweet *t = &tweet_map[user_array[select]][index_array[select]];
                result.push_back(t->id);
                index_array[select] += 1;
                count += 1;
            } else all_empty = true;
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        // 当前用户不存在则新建
        if (users.find(followerId) == users.end()) users.insert(followerId);
        // 不可以自己关注自己
        if (followerId == followeeId) return;
        // 被关注的用户不存在则新建
        if (users.find(followeeId) == users.end()) users.insert(followeeId);
        follow_map[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        // 当前用户不存在则新建
        if (users.find(followerId) == users.end()) users.insert(followerId);
        // 不可以自己取关自己
        if (followerId == followeeId) return;
        // 被取关的用户不存在则新建
        if (users.find(followeeId) == users.end()) users.insert(followeeId);
        follow_map[followerId].erase(followeeId);
    }
};

/**
* Your Twitter object will be instantiated and called as such:
* Twitter* obj = new Twitter();
* obj->postTweet(userId,tweetId);
* vector<int> param_2 = obj->getNewsFeed(userId);
* obj->follow(followerId,followeeId);
* obj->unfollow(followerId,followeeId);
*/

int main(int argc, const char * argv[]) {
    Twitter *twitter = new Twitter();
    twitter->postTweet(1, 5);
    twitter->getNewsFeed(1);
    twitter->follow(1, 2);
    twitter->postTweet(2, 6);
    twitter->getNewsFeed(1);
    twitter->unfollow(1, 2);
    twitter->getNewsFeed(1);
    return 0;
}
