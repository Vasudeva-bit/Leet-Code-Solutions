class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string> result;
        int count = 0;
        if(n >= 0) {
            result.push_back("0");
            count++;
        }
        if(n >= 1) {
            result.push_back("1");
            count++;
        }
        while(count <= n) {
            vector<string> tem;
            for(int i=0;i<result.size();i++) {
                tem.push_back("0"+result[i]);
            }
            for(int i=result.size()-1;i>=0;i--) {
                tem.push_back("1"+result[i]);
            }
            result = tem;
            count++;
        }
        vector<int> int_result;
        for(auto i:result) {
            int_result.push_back(stoi(i, 0, 2));
        }
        return int_result;
    }
};