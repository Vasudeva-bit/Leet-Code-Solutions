class Solution {
public:
    string reverseWords(string s) {
        int l = 0;
        int r;
        s = s+" ";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                int r = i-1;
                while(l < r){
                    swap(s[l], s[r]);
                    l++;
                    r--;
                }
                l = i+1;
            }
        }
        return s.substr(0, s.size()-1);
    }
};