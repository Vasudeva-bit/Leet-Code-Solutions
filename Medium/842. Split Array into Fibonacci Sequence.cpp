class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> result;
        helper(num, result, 0);
        return result;
    }
    bool helper(string num, vector<int>& result, int pos) {
        if(pos == num.size()) {
            return (result.size() > 2);
        }
        long val = 0;
        for(int i=pos;i<num.size();i++) {
            val = val*10 + num[i]-'0';
            if(val > INT_MAX) return false;
            if(result.size()<2 || long(result[result.size()-1])+long(result[result.size()-2]) == val) {
                result.push_back(val);
                if(helper(num, result, i+1)) return true;
                result.pop_back();
            }
            if(i == pos && num[i] == '0') return false;
        }
        return false;
    }
};