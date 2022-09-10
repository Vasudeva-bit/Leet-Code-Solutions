class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        bed.insert(bed.begin(), 0);
        bed.push_back(0);
        for(int i=1;i<bed.size()-1;i++) {
            if(bed[i-1] == 0 and bed[i] == 0 and bed[i+1] == 0 and n){
                n--;
                i++;
            }
        }
        return n==0;
    }
};