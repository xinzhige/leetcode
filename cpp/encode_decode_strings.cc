class Codec {
public:

  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string result;
    for (const auto &s : strs) {
      result.append(to_string(s.size()) + "/" + s);
    }
    return result;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> result;
    for (int i = 0; i < s.size(); ++i) {
      int j = s.find('/', i);
      int len = stoi(s.substr(i, j - i));
      result.push_back(s.substr(j+1, len));
      i = j + len;
    }
    return result;
  }
};
