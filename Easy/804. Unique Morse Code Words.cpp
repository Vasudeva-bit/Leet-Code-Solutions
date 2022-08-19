class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
  	vector<string> trans = {".-","-...","-.-.","-..",".","..-.","--.","....",
                  "..",".---","-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
      unordered_map<string, int> umap;
     for(auto w: words){
         string tem = "";
         for(int i=0;i<w.size();i++){
             tem += trans[w[i] - 'a'];
            }
         umap[tem]++;
         }
      
      return umap.size();
     
    }
};