class Solution {
public:
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j) {
            while(i<j) {
                if(s[i] == 'a' or s[i] =='i' or s[i] == 'o' or s[i] == 'e' or s[i] == 'u' or
                   s[i] == 'A' or s[i] =='I' or s[i] == 'O' or s[i] == 'E' or s[i] == 'U')
                    break;
                else
                    i++;
            }
            while(i<j) {
                if(s[j] == 'a' or s[j] =='i' or s[j] == 'o' or s[j] == 'e' or s[j] == 'u' or
                   s[j] == 'A' or s[j] =='I' or s[j] == 'O' or s[j] == 'E' or s[j] == 'U')
                    break;
                else
                    j--;
            }
            if(i < j)
                swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};