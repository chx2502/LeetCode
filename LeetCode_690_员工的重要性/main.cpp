#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
private:
    unordered_map <int, Employee*> memo;
    int importance(Employee *e) {
        if (!e) return 0;
        int result = e->importance;
        for (auto const& s : e->subordinates) {
            result += importance(memo[s]);
        }
        return result;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto const &e : employees) {
            memo[e->id] = e;
        }
        return importance(memo[id]);
    }
};