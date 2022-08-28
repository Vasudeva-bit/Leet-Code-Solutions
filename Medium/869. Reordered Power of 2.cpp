class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int tem = n;
        unordered_map<int ,int> umap;
        while(tem > 0) {
            umap[tem%10]++;
            tem /= 10;
        }
        long long a = 1;
        int i = 0;
        while(i < 32) { // Power of bit-manipulations
            a = 1LL<<i;
            unordered_map<int, int> freq;
            while(a > 0) {
                freq[a%10]++;
                a /= 10;
            }
            i++;
            int flag = true;
            for(int j=0;j<=9;j++) {
                if(freq[j] != umap[j])
                    flag = false;
            }
            if(flag) 
                return true;
        }
        return false;
    }
};