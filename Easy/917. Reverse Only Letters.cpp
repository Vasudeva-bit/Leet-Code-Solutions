class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        vector<int> result;
        for(int i=0;i<n;i++) {
            result.push_back(s[i]);
        }
        while(i < j) {
            if(!isalpha(result[i])) i++;
            if(!isalpha(result[j])) j--;
            if(i < j and isalpha(result[i]) and isalpha(result[j])) {
                swap(result[i], result[j]);
                i++;
                j--;
            }
        }
        string res="";
        for(auto val:result) {
            res += val;
        }
        return res;
    }
};