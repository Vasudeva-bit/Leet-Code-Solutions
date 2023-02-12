class Solution {
public:
    bool check(string& word) {
        int n = word.size()-1;
        if((word[0] == 'a' or word[0] == 'e' or word[0] == 'i' or word[0] == 'o' or word[0] == 'u') and
          (word[n] == 'a' or word[n] == 'e' or word[n] == 'i' or word[n] == 'o' or word[n] == 'u'))
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> out(queries.size());
        vector<int> prefix_sum(n);
        prefix_sum[0] = 0;
        for(int i=0;i<n;i++) {
            if(check(words[i]))
                if(i != 0)
                    prefix_sum[i] = prefix_sum[i-1]+1;
                else
                    prefix_sum[i]++;
            else if(i != 0)
                prefix_sum[i] = prefix_sum[i-1];
        }
        int i=0;
        for(auto query: queries) {
            if(query[0] == 0)
                out[i++] = prefix_sum[query[1]];
            else
                out[i++] = prefix_sum[query[1]]-prefix_sum[query[0]-1];
        }
        return out;
    }
};