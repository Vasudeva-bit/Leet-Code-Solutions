class Solution {
public:
    int minimumScore(string s, string t) {
        int m = s.size(), n = t.size();\
        vector<int> suffix(n, -1);
        int k = n - 1;
        for (int i = m - 1; i >= 0 && k >= 0; --i) {
            if (s[i] == t[k]) {
                suffix[k--] = i;
            }
        }
        if (k < 0) {
            return 0;
        }        
        int minScore = k + 1;
        vector<int> prefix(n, -1);
        k = 0;
        for (int i = 0; i < m && k < n; ++i) {
            if (s[i] == t[k]) {
                prefix[k++] = i;
            }
        }
        if (k >= n) {
            return 0;
        }
        minScore = min(minScore, n - k);
        

        for (int i = 0; i < n; i++) {
            if (prefix[i] != -1) {
                int leftMost = prefix[i];
                
                int j = n - 1;
                while(j >= 0 && suffix[j] > leftMost) {
                    j--;
                }
                if (j == -1) {
                    minScore = min(minScore, n - 1 + 1);
                } else {
                    int score = j - (i + 1) + 1;
                    minScore = min(minScore, score);
                }
            }
        }
        
        return minScore;
    }
};