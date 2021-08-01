class Solution {
public:

    // Encodes a URL to a shortened URL.
    map<string,string> mp;
    map<string,string> shortToLarge;
    int i = 0;
    string encode(string longUrl) {
        mp[longUrl] = "tinyUrl.com/" + to_string(i++);
        shortToLarge[mp[longUrl]] = longUrl;
        return mp[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shortToLarge[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));