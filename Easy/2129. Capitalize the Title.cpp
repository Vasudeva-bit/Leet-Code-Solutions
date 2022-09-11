class Solution {
public:
string capitalizeTitle(string t) {

    int n = t.size();
    
    
    for(int i = 0; i < n; i++)
    {
        t[i] = tolower(t[i]);
    }
    
    if(n == 1 || n == 2)
        return t;
    
    if(t[1] != ' ' && t[2] != ' ')
        t[0] = toupper(t[0]);
    
    for(int i = 1; i < n; i++){
        if(i + 1 < n && i + 3 < n){
            if((t[i] == ' ') && (t[i+1] != ' ' && t[i + 3] != ' ' && t[i + 2] != ' '))
        {
               t[i + 1] = toupper(t[i + 1]);
        }
            else{
                 continue;
            }
        }
    }
    
    return t;
}
};