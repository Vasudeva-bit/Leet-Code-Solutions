class Solution {
public:
    string addBinary(string a, string b) {
        string out = "";
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int len = max(a.size(), b.size());
        for(int i=0;i<len;i++) {
            int d1 = (i < a.size())? int(a[i]) - int('0'):0;
            int d2 = (i < b.size())? int(b[i]) - int('0'):0;
            carry = d1 + d2 + carry;
            out = to_string(carry%2) + out;
            carry = carry/2;
        }
        if(carry)
            out = '1'+out;
        return out;
    }
};