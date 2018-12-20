class Solution {
public:
  int lengthLongestPath(string input) {
    istringstream is(input);
    string line;
    map<int, int> index{{0, 0}};
    int result = 0;
    while (getline(is, line)) {
      int level = line.find_last_of('\t') + 1;
      int len = line.substr(level).size();
      if (line.find('.') != string::npos) {
        result = max(result, index[level] + len);
      } else {
        index[level + 1] = index[level] + len + 1;
      }
    }
    return result;
  }
};
