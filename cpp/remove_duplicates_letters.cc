class Solution {
public:
  string removeDuplicateLetters(string s) {
    map<char, int> freq;
    map<char, bool> visited;
    for (const char &c : s) {
      freq[c] += 1;
    }
    string result = "0";
    for (const char &c : s) {
      freq[c] -= 1;
      if (!visited[c]) {
        while (result.back() > c && freq[result.back()] > 0) {
          visited[result.back()] = false;
          result.pop_back();
        }
        result += c;
        visited[c] = true;
      }
    }
    return result.substr(1);
  }
};
