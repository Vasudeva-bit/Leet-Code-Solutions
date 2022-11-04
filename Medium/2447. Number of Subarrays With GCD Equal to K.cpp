class Solution {
public:
    int gcd_(int a, int b) {
        if(a == 0)
            return b;
        return gcd(b%a, a);
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int c = 0;
        for(int i=0;i<n;i++) {
            int gcd = nums[i];
            for(int j=i;j<n;j++) {
                gcd = gcd_(gcd, nums[j]);
                if(gcd == k)
                    c++;
                if(gcd < k)
                    break;
            }
        }
        return c;
    }
};