#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int ops = INT_MAX;
        char ch = '7';
        for(int i=0;i<n;i++) {
            if(num[i] == ch) {
                string s = num.substr(i+1);
                if(s.find('5') != string::npos) {
                    ops = min(ops, n-(i+2));
                }
            }
        }
        
        ch = '0';
        for(int i=0;i<n;i++) {
            if(num[i] == ch) {
                string s = num.substr(i+1);
                if(s.find('0') != string::npos) {
                    ops = min(ops, n-(i+2));
                }
            }
        }
        
        ch = '5';
        for(int i=0;i<n;i++) {
            if(num[i] == ch) {
                string s = num.substr(i+1);
                if(s.find('0') != string::npos) {
                    ops = min(ops, n-(i+2));
                }
            }
        }
        
        ch = '2';
        for(int i=0;i<n;i++) {
            if(num[i] == ch) {
                string s = num.substr(i+1);
                if(s.find('5') != string::npos) {
                    ops = min(ops, n-(i+2));
                }
            }
        }
        if(ops == INT_MAX) {
            if(num.find('0') != string::npos) return num.size()-1;
            else return num.size();
        }
        return ops;
    }
};