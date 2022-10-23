class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        string output(n, '1');
        int count = 0;
        for(auto ch:binary) {
            if(ch == '0')
                count++;
        }
        for(int i=0;i<n;i++) {
            if(binary[i] == '0') {
                output[i+count-1] = '0';
                return output;
            }
        }
        return output;
    }
};