class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(auto a:asteroids) {
            while((!st.empty()) and st.back() > 0 and a < 0) {
                int diff = a + st.back();
                if(diff > 0)
                    a = 0;
                else if(diff < 0)
                    st.pop_back();
                else {
                    a = 0;
                    st.pop_back();
                }
            }
            if(a)
                st.push_back(a);
        }
        return st;
    }
};