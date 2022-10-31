class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(b == "")
            return 0;
        int repeat = b.size()/a.size();
        int count = 1;
        string tmp_a = a;
        for(int i=0;i<repeat+2;i++) {
            if(a.find(b) != string::npos) 
                return count;
            else {
                a += tmp_a;
                count++;
            }
        }
        return -1;
    }
};