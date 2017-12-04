class Solution {
public:
  int romanToInt(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
      if (i < s.size() - 1 && mymap[s[i]] < mymap[s[i + 1]]) {
	num -= mymap[s[i]];
      } else {
	num += mymap[s[i]];
      }
    }
    return num;
  }

private:
  unordered_map<char, int> mymap = {{ 'I' , 1 },
				    { 'V' , 5 },
				    { 'X' , 10 },
				    { 'L' , 50 },
				    { 'C' , 100 },
				    { 'D' , 500 },
				    { 'M' , 1000 }};
};
