// DP
class Solution { 
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    vector<bool> word(s.size() + 1, false);
    word[0] = true;
    for (int i = 1; i < s.size() + 1; i++) {
      for (int j = i - 1; j >= 0; j--) {
      	if (word[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
      	  word[i] = true;
      	  break;
      	}
      }
    }
    return word[s.size()];
  }
};

// in case the length of dict is far less than that of string s
class Solution { 
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    vector<bool> wb(s.size() + 1, false);
    wb[0] = true;
    for(int i = 1; i <= s.size(); ++i) {
      for(unordered_set<string>::iterator it = dict.begin(); 
          it != dict.end(); ++it) {
        int length = (*it).size();
	      if((i - length >= 0) && wb[i - length] && 
           (s.substr(i - length, length) == *it)) {
	        wb[i] = true;
	        break;
	      }
      }
    }
    return wb[s.size()];
  }
};
