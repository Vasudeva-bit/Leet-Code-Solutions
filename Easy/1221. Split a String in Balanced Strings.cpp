class Solution {
public:
    int balancedStringSplit(string s) {
        int right = 0;
        int count = 0;
        for(auto ch:s) {
            if(ch == 'L')
                right--;
            else
                right++;
            if(right == 0)
                count++;
        }
        return count;
    }
};