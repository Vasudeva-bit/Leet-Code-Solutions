class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int st = stamp.size();
        int tr = target.size();
        int moves = 0;
        vector<int> result;
        while(moves < 10*target.size()) {
            int premove = moves;
            for(int i=0;i<tr-st+1;i++) {
                if(compare(target.substr(i, st), stamp)) {
                    moves++;
                    result.push_back(i);
                    target = target.substr(0, i) + string(st, '?') + target.substr(i+st, tr);
                    if(target == string(tr, '?')) {
                        reverse(result.begin(), result.end());
                        return result;
                    }
                }
            }
            if(premove == moves)
                return {};
        }
        return {};
    }
    bool compare(string src, string trg) {
        bool flag = false;
        for(int i=0;i<src.size();i++) {
            if(trg[i] == src[i])
                flag = true;
            else if(src[i] == '?')
                continue;
            else
                return false;
        }
        return flag;
    }
};