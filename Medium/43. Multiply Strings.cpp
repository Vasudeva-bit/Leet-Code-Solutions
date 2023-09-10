#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0") return "0";
        string sign = "";
        if(!(num1[0] == '-' and num2[1] == '-')) {
            if(num1[0] == '-' or num2[0] == '-') {
                sign += '-';
            }
        }
        int n = num1.size();
        int m = num2.size();
        string out(n+m, '0');
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                int mul = (num1[i]-'0')*(num2[j]-'0')+(out[i+j+1]-'0');
                out[i+j+1] = mul%10+'0';
                out[i+j] += mul/10;
            }
        }
        int i = 0;
        while(i < out.size() and out[i] == '0') {
            i++;
        }
        return sign+out.substr(i);
    }
};