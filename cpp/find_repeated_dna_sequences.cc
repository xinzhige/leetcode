class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> result;
    size_t s_length = s.size();
    if (s_length <= 10) {
      return result;
    }
    const int kSequences = 1024*1024;
    int times[kSequences] = { 0 };
    for (int i = 0; i <= s_length - 10; i++) {
      string tmp = s.substr(i, i + 10);
      int key = hashCode(tmp);
      if (times[key] == 1) { 
	result.push_back(tmp);
      }
      times[key] += 1; 
    }
    return result;
  }

  int hashCode(String str) {
    int hash = 0;
      for (int i = 0; i < str.size(); i++) {
        hash = hash << 2 | mapInteger(str[i]);
      }
    return hash;
  }
  
  int mapInteger(char ch) {
        switch (ch) {
          case 'A':
            return 0;
          case 'C':
            return 1;
          case 'G':
            return 2;
          case 'T':
            return 3;
          default:
            return 0;
        }
    }
};
