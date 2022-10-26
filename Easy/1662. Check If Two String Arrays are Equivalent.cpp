class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1 = "";
        for(auto var:word1) {
            w1 += var;
        }
        string w2 = "";
        for(auto var:word2) {
            w2 += var;
        }
        if(w1.compare(w2))
            return false;
        else
            return true;
    }
};