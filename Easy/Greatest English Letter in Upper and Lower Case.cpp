class Solution {
public:
    string greatestLetter(string s) {
        string result;
        for(int i='a';i<='z';i++){
            if((s.find(char(i)) != std::string::npos) && (s.find(char(i-32)) != std::string::npos))
                result = char(i-32);
        }
        return result;
    }
};