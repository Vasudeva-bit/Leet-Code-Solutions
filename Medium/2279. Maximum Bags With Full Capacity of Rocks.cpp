class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int addRocks) {
        int index = 0;
        for(auto it:capacity) {
            rocks[index] = it - rocks[index];
            index++;
        }
        index = 0;
        sort(rocks.begin(), rocks.end());
        int result = 0;
        while(addRocks > 0 && index < rocks.size()) {
            if(rocks[index] > addRocks) {
                break;
            }
            else {
                result++;
                addRocks -= rocks[index++];
            }
        }
        return result;
    }
};