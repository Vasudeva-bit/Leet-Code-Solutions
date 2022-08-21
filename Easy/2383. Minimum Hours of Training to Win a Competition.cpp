class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int result = max(0, accumulate(energy.begin(), energy.end(), 0)-initialEnergy+1);
        for(int i=0;i<energy.size();i++) {
            
            if(experience[i] >= initialExperience) {
                result += experience[i] - initialExperience + 1;
                initialExperience = experience[i] + 1;
            }
            initialExperience += experience[i];            
        }
        return result;
    }
};