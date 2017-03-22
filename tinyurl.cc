class Solution {
public:

  string getRand() {
    string s;
    for (int i = 0; i < 6; i++) {
      s += alphabet[rand() % 62];
    }
    return s;
  }

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    while (mymap.count(key)) {
      key = getRand();
    }
    mymap[key] = longUrl;
    return "http://tinyurl.com/" + key;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    return mymap.get(shortUrl.replace("http://tinyurl.com/", ""));
  }

private:
  string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  unordered_map<string, string> mymap;
  string key;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
