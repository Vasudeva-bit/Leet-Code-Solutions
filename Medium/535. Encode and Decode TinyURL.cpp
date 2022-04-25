class Solution {
public:
    unordered_map<string, string> encode_umap;
    unordered_map<string, string> decode_umap;
    string base = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = base+to_string(encode_umap.size()+1);
        if(encode_umap.find(longUrl) == encode_umap.end()){
            encode_umap[longUrl] = shortUrl;
            decode_umap[shortUrl] = longUrl;
        }
        return encode_umap[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decode_umap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
