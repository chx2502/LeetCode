//
//  main.cpp
//  LeetCode_127
//
//  Created by chx on 2020/11/5.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    unordered_map<string, int> wordMap;
    vector<bool> visited;
    vector<vector<int>> createGraph(vector<string>& wordList) {
        int size = (int)wordList.size();
        vector<vector<int>> graph(size);
        for (int i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                int count = 0;
                for (int k = 0; k < wordList[i].length(); k++) {
                    if (wordList[i][k] != wordList[j][k]) count++;
                    if (count > 1) break;
                }
                if (count < 2) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        return graph;
    }
    
    int bfs(vector<vector<int>>& graph, int begin, int end, int step) {
        queue<int> q1;
        queue<int> q2;
        q1.push(begin);
        while (!q1.empty()) {
            step += 1;
            while (!q1.empty()) {
                int curr = q1.front();
                q1.pop();
                visited[curr] = true;
                if (curr == end) return step;
                for (int next : graph[curr]) {
                    if (!visited[next]) q2.push(next);
                }
            }
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int size = (int)wordList.size();
        bool flag = false;
        for (int i = 0; i < size; i++) {
            string temp = wordList[i];
            if (beginWord.compare(temp) == 0) flag = true;
            wordMap[wordList[i]] = i;
        }
        if (wordMap.count(endWord) == 0) return 0;
        visited.assign(size, false);
        if (!flag) {
            wordMap[beginWord] = size;
            wordList.push_back(beginWord);
            visited.push_back(false);
            size++;
        }
        vector<vector<int>> graph = createGraph(wordList);
        return bfs(graph, wordMap[beginWord], wordMap[endWord], 0);
    }
};

int main(int argc, const char * argv[]) {
    vector<string> wordList = { "si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    string beginWord = "qa";
    string endWord = "sq";
    Solution s;
    int res = s.ladderLength(beginWord, endWord, wordList);
    return 0;
}
