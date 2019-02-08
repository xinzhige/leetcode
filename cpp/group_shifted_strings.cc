class Solution {
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> mymap;
    for (const auto &s : strings) {
      string temp = "";
      for (const char &c : s) {
        // Add 26 to avoid negative value.
        int offset = (c + 26 - s[0]) % 26;
        // Add "," in case the offset is double digits
        // like "0,1,2," and "0,12,".
        temp += to_string(offset) + ",";
      }
      mymap[temp].push_back(s);
    }
    for (const auto &it : mymap) {
      result.push_back(it.second);
    }
    return result;
  }
};
