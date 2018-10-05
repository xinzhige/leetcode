class Solution {
public:
  string toGoatLatin(string S) {
    const string vowls = "aeiouAEIOU";
    string result;
    string word;
    int index = 1;
    istringstream s(S);
    while (s >> word) {
      if (vowls.find(word[0]) == string::npos){
        word = word.substr(1) + word[0];
      }
      result += " " + word + "ma" + string(index, 'a');
      index += 1;
    }
    return result.substr(1);
  }
};
