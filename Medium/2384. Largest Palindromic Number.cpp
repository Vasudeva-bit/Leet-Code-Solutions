class Solution {
public:
    string largestPalindromic(string num) {
        unordered_map<int, int> freq;
        for(auto ch:num) {
            freq[ch-'0']++;
        }
        int check = 0;
        string left = "";
        for(int i=9;i>=0;i--) {
            if(i == 0 and check == 0)
                break;
            while(freq[i] > 1) {
                check = 1;
                left += to_string(i);
                freq[i] -= 2;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        for(int i=9;i>=0;i--) {
            if(freq[i] > 0)
                return left + to_string(i) + right;
        }
        return left+right;
    }
};







