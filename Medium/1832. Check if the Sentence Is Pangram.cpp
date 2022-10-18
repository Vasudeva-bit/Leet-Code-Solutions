class Solution {
public:
    bool checkIfPangram(string sentence) {
        for(char a='a';a<='z';a++) {
            if(sentence.find(a) == string::npos)
                return false;
        }
        return true;
    }
};