class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<long long> result;
        return helper(num, result, 0);
    }
    bool helper(string num, vector<long long>& result, int pos) {
        if(pos == num.size()) {
            return result.size() > 2;
        }
        unsigned long long val = 0;
        for(int i=pos;i<num.size();i++) {
            val = val*10 + num[i] - '0';
            if(val < 0 || val > ULLONG_MAX) return false;
            if(result.size() < 2 || (long long)(result[result.size()-1]) + (long long)(result[result.size()-2]) == val) {
                result.push_back(val);
                if(helper(num, result, i+1)) return true;
                result.pop_back();
            }
            if(i == pos && num[i] == '0') return false; 
        }
        return false;
    }
};