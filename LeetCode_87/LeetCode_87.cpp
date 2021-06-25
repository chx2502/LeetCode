#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<vector<bool>>> dp;

public:
    bool isScramble(string s1, string s2) {
        
    }
};  

int main(){
    Solution s;
    string s1 = "great";
    string s2 = "rgeat";
    bool result = s.isScramble(s1, s2);
    cout << result << endl;
    return 0;
}
