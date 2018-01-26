class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    unordered_map<string, int> seq;
    for (int i = 10; i <= s.size(); ++i) {
      string curr = s.substr(i-10, 10);
      if (seq.count(curr) > 0) {
        if (seq[curr] == 1) {
          result.push_back(curr);
        }
        seq[curr] = 2;
      } else {
        seq[curr] = 1;
      }
    }
    return result;
  }
};

// Less memory
class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    unordered_map<int, int> seq;
    for (int i = 10; i <= s.size(); ++i) {
      auto curr = s.substr(i-10, 10);
      int code = encode(curr);
      if (seq.count(code) > 0) {
        if (seq[code] == 1) {
          result.push_back(curr);
        }
        seq[code] = 2;
      } else {
        seq[code] = 1;
      }
    }
    return result;
  }
  int encode(string s) {
    int code = 0;
    for (auto &c : s) {
      code <<= 2;
      if (c == 'A') {
        continue;
      } else if (c == 'C') {
        code += 1;
      } else if (c == 'G') {
        code += 2;
      } else {
        code += 3;
      }
    }
    return code;
  }
};
