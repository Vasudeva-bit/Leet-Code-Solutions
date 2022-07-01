class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int result = 0;
        int index = 0;
        while(truckSize > 0 && index < boxTypes.size()) {
            if(truckSize < boxTypes[index][0]) {
                result += (truckSize)*boxTypes[index++][1];
                truckSize = 0;
            }
            else {
                result += boxTypes[index][0] * boxTypes[index][1];
                truckSize -= boxTypes[index++][0];
            }
        }
        return result;
    }
};