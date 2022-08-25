class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;
        for(auto ch:magazine) {
            freq[ch]++;
        }
        for(auto ch:ransomNote) {
            if(freq[ch] < 1) {
                return false;
            }
            freq[ch]--;
        }
        return true;
    }
};