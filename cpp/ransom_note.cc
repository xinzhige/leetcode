class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> freq(26, 0);
    for (int i = 0; i < magazine.size(); ++i) {
      freq[magazine[i] - 'a'] += 1;
    }
    for (int i = 0; i < ransomNote.size(); ++i) {
      freq[ransomNote[i] - 'a'] -= 1;
      if(freq[ransomNote[i] - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};
