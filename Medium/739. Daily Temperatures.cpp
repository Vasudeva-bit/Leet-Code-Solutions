class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        if(temps.size() == 1) return temps;
        stack<int> st;
        vector<int> result(temps.size());
        for(int i=0;i<temps.size();i++) {
            while(!st.empty() and temps[i]>temps[st.top()]) {
                result[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};