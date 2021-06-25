//
//  main.cpp
//  LeetCode_721
//
//  Created by chx on 2021/4/29.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct user {
    string name;
    unordered_set<string> emails;
    user(string _name, vector<string> _emails): name(_name) {
        for (auto &email : _emails) emails.insert(email);
    };
};

class Solution {
private:
    unordered_map<string, user*> accountMap;
    vector<user*> users;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for (auto &account : accounts) {
            string name = account[0];
            vector<string> emails;
            auto it = accountMap.end();
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                emails.push_back(email);
                if (it == accountMap.end()) it = accountMap.find(email);
            }
            if (it != accountMap.end()) {
                for (auto &email : emails) {
                    it->second->emails.insert(email);
                }
            } else {
                user *newUser = new user(name, emails);
                for (auto &email : emails) {
                    accountMap[email] = newUser;
                }
                users.push_back(newUser);
            }
        }
        vector<vector<string>> result;
        for (auto &u : users) {
            vector<string> row;
//            row.push_back(u->name);
            for (auto &email : u->emails) row.push_back(email);
            sort(row.begin(), row.end());
            row.insert(row.begin(), u->name);
            result.push_back(row);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
