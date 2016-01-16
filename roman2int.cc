class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char,int> my_map;
    my_map['I'] = 1;
    my_map['V'] = 5;
    my_map['X'] = 10;
    my_map['L'] = 50;
    my_map['C'] = 100;
    my_map['D'] = 500;
    my_map['M'] = 1000;
    int sum = 0;
    int s_len = s.size();
    for (int i = 0; i < s_len; ++i) {
      int sign = 1;
      if ((my_map[s[i]] < my_map[s[i+1]]) && (i < s_len-1)) {
	sign = -1;  
      }
      sum += my_map[s[i]] * sign;
    }
    return sum;
  }
};
