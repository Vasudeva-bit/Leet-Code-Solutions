class Solution {
public:
static bool cmp(string &s1,string &s2){
    return s1.length()<s2.length();
}
bool check(string &s1, string &s2){
    if(s1.length() != s2.length() + 1)return false;
    int i = 0;
    int j = 0;
    while(i < s1.length()){
        if(s1[i] == s2[j]){
            i++;
            j++;
        }
        else
            i++;
    }
    if(i == s1.length() && j == s2.length())return true;
    return false;
}
    
int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), cmp);
    int n = words.size();
    vector<int> dp(n, 1);
    int maxi = 0;
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(check(words[i], words[prev]) && dp[i]<dp[prev]+1){
                dp[i] = dp[prev] + 1;
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
} 
};