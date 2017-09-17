class Solution {
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> mymap;
    for (auto &s : strings) {
      string tmp = "";
      for (char &c : s) {
        int offset = (c + 26 - s[0]) % 26;
        // Add "," in case the offset is double digits
        // like "0,1,2," and "0,12,"
        tmp += to_string(offset) + ",";
      }
      mymap[tmp].push_back(s);
    }
    for (auto it = mymap.begin(); it != mymap.end(); ++it) {
      result.push_back(it->second);
    }
    return result;
  }
};
