class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
		if(longHash.count(longUrl)) return longHash[longUrl]; 
		string shortUrl = url + generateCode(6);
		longHash[longUrl] = shortUrl;
		shortHash[shortUrl] = longUrl;
		return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
		if(shortHash.count(shortUrl))
		{
			return shortHash[shortUrl];
		}
		return string();
    }

	string generateCode(int length) {
		string code = "";
		for(int i = 0; i < length; i += 1)
		{
			code += codeTable[rand() % codeTable.size()];
		}
		return code;
	}

private:
	unordered_map<string, string> longHash;
	unordered_map<string, string> shortHash;
	string codeTable = "ABCDEFGHIJKLMNOPKRSTUVWXYZabcdefghijklmnopkrstuvwxyz0123456789";
	string url = "tinyurl.com/";
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
