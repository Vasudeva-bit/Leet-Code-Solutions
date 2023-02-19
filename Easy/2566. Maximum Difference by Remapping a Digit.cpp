#include <bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int minMaxDifference(int num) {
        string n = to_string(num);
        string min = "";
        string max = "";
        int i=0;
        while(i < n.size() and n[i] == '9')  {
            i++;
        }
        if(i < n.size()) {
            char remax = n[i];
            for(auto val: n) {
                if(val == remax)
                    max += '9';
                else
                    max += val;
            }
        }
        else
            max = n;
        i=0;
        while(i < n.size() and n[i] == '0') 
            i++;
        if(i < n.size()) {
            char remin = n[i];
            for(auto val: n) {
                if(val == remin)
                    min += '0';
                else
                    min += val;
            }
        }
        else
            min = n;
        return stoi(max)-stoi(min);
    }
};