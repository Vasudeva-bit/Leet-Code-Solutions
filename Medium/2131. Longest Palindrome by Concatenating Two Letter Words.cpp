class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for(auto word:words) {
            freq[word]++;
        }
        int out = 0;
        int extra = 0;
        for(auto it:freq) {
            string revers = it.first;
            reverse(revers.begin(), revers.end());
            if(it.first.compare(revers) == 0) {
                if(it.second%2) {
                    out += (it.second-1)*2;
                    extra = 2;
                }
                else 
                    out += it.second*2;
                freq[it.first] = 0;
            }
            else if(freq[it.first] and freq[revers]) {
                int p = min(freq[it.first], freq[revers]);
                out += p*4;
                freq[it.first] -= p;
                freq[revers] -= p;
            }
        }
        return out+extra;
    }
};