#include <bits/stdc++.h>
using namespace std;
// tags: BFS, Adjacency Matrix, Graphs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> adjMat;
        int n = beginWord.size();
        wordList.push_back(beginWord);
        for(auto word: wordList) {
            for(int i=0;i<n;i++) {
                string pattern = word.substr(0, i) +"*"+ word.substr(i+1);
                adjMat[pattern].push_back(word);
            }
        }
        int out = 1;
        queue<string> q;
        set<string> seen;
        q.push(beginWord);
        seen.insert(beginWord);
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                string word = q.front();
                q.pop();
                if(word == endWord)
                    return out;
                for(int t=0;t<n;t++) {
                    string pattern = word.substr(0, t) +"*"+ word.substr(t+1);
                    for(auto adj: adjMat[pattern]) {
                        if(seen.find(adj) == seen.end()) {
                            q.push(adj);
                            seen.insert(adj);
                        }
                    }
                }
            }
            out++;
        }
        return 0;
    }
};