class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> phash(26, 0);
        vector<int> hash(26, 0);
        int window = p.size();
        int len = s.size();
        if(window > len)
            return {};
        int left=0, right=0;
        while(right < window) {
            phash[p[right]-'a']++;
            hash[s[right]-'a']++;
            right++;
        }
        right--;
        vector<int> out;
        while(right < len) {
            if(phash == hash)
                out.push_back(left);
            right++;
            if(right != len) {
                hash[s[right]-'a']++;
            }
            hash[s[left]-'a']--;
            left++;
        }
        return out;
    }
};