class Solution {
public:
  string numberToWords(int num) {
    if (num == 0) {
      return dict1[0];
    }
    vector<string> ret;
    for(; num > 0; num /= 1000) {
      ret.push_back(hunderds2Words(num % 1000));
    }
    string result = ret[0];
    for (int i = 1; i < ret.size(); i++) {
      if (ret[i].size() > 0) {
        if (result.size() > 0) {
          result = ret[i] + " " + dict3[i] + " " + result;
        } else {
          result = ret[i] + " " + dict3[i];
        }
      }
    }
    return result;
  }
  string hunderds2Words(int num) {
    string result;
    if (num == 0) {
      return result;
    } else if (num < 20) {
      return dict1[num];
    } else if (num < 100) {
      result = dict2[num / 10];
      if (num % 10 > 0) {
        result += " " + dict1[num % 10];
      }
    } else {
      result = dict1[num / 100] + " " + dict3[0];
      if (num % 100 > 0) {
        result += " " + hunderds2Words(num % 100);
      }
    }
    return result;
  }

private:
  const vector<string> dict1 = {"Zero","One", "Two", "Three", "Four", "Five",
                                "Six", "Seven", "Eight", "Nine", "Ten",
                                "Eleven", "Twelve", "Thirteen", "Fourteen",
                                "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                                "Nineteen"};
  const vector<string> dict2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                                "Sixty", "Seventy", "Eighty", "Ninety" };
  const vector<string> dict3 = {"Hundred", "Thousand", "Million", "Billion" };
};
