class WordFilter {
public:
    unordered_map<string, int> umap;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            string const& word = words[i];
            int const len = words[i].size();
            for(int j=1;j<=len;j++){
                string some = word.substr(0, j);
                some += '@';
                for(int k=1;k<=len;k++){
                    some.resize(j+1);
                    some.append(word, len-k, k);
                    umap[some] = i;
                }
            }
        }
        
    }
    
    int f(string prefix, string suffix) {
        string some = prefix + '@' + suffix;
        return (umap.find(some) != umap.end())? umap[some] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */