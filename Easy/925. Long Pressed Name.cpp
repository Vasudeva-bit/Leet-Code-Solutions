class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(typed[0] != name[0] or typed[typed.size()-1] != name[name.size()-1]) return false;
        int j = 0;
        for(int i=0;i<typed.size();i++) {
            if(typed[i] == name[j])j++;
            else if(j > 0 and typed[i] != name[j-1]) return false;
        }
        return j == name.size();
    }
};