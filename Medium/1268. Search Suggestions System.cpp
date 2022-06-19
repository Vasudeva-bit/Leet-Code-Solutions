class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string word) {
        sort(products.begin(), products.end());
        int l = 0;
        int r = products.size()-1;
        vector<vector<string>> result;
        for(int i=0;i<word.size();i++){
            vector<string> temp;
            while(l<=r && ((i >= products[l].size()) || (products[l][i] != word[i]))){
                l++;
            }
            while(l<=r &&((i >= products[r].size()) || (products[r][i] != word[i]))){
                r--;
            }
            for(int j=0;j<min(3, r-l+1);j++){
                temp.push_back(products[j+l]);
            }
            result.push_back(temp);
        }
        return result;
    }
};