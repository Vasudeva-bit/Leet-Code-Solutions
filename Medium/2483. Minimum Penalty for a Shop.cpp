#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int bestClosingTime(string s) {
        int hour = 0;
        int maxscore = 0;
        int score = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i] == 'Y') score++;
            else score--;
            if(score > maxscore) {
                maxscore = score;
                hour = i+1;
            }
        }
        return hour;
    }
};