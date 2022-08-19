class Solution {
public:
    string convert(int &n) {
        string s="";
        while(n)
        {
            int rem = n%2;
            s+=to_string(rem);
            n=n/2;
        }
        return s;
    }

    int binaryGap(int n) {
        vector<int> v;
        string s = convert(n);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                v.push_back(i);
            }
        }
        int maxi=0;
        for(int i=0;i<v.size()-1;i++)
        {
            maxi=max(maxi,abs(v[i+1]-v[i]));
        }
        return maxi;
    }
};