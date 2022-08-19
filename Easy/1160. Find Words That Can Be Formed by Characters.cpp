class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> umap;
        for(int i=0;i<chars.size();i++) {
            umap[chars[i]]++;
        }
        unordered_map<char, int> temp;
        int result = 0;
        for(auto word:words) {
            temp = umap;
            bool flag = true;
            for(int i=0;i<word.size();i++) {
                if(temp.find(word[i]) != temp.end()) {
                    temp[word[i]]--;
                    if(temp[word[i]] == 0)
                        temp.erase(word[i]);
                }
                else
                    flag = false;
            }
            if(flag) {
                result += word.size();
            }
        }
        return result;
    }
};