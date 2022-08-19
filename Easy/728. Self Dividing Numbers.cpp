class Solution {
public:
    bool self_divides(int n) {
        int dup = n;
        while(dup > 0) {
            int l = dup%10;
            if(l == 0 or n % l != 0)
                return false;
            dup /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        while(left <= right) {
            if(self_divides(left)) {
                result.push_back(left);
            }
            left++;
        }
        return result;
    }
};