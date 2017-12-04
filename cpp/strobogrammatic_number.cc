// Without hash table
class Solution {
public:
  bool isStrobogrammatic(string num) {
    for (int left = 0, right = num.size() - 1; left <= right; left++, right--) {
      if ((num[left] == '0' && num[right] == '0') ||
          (num[left] == '1' && num[right] == '1') ||
          (num[left] == '8' && num[right] == '8')) {
        continue;
      } else if ((num[left] == '6' && num[right] == '9') ||
                 (num[left] == '9' && num[right] == '6')) {
        if (left == right) {
          return false;
        }
      } else {
        return false;
      }
    }
    return true;
  }
};

// With hash table
class Solution {
public:
  bool isStrobogrammatic(string num) {
    unordered_map<char, char> mymap{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    for (int left = 0, right = num.size() - 1; left <= right; left++, right--) {
      if (mymap.find(num[left]) == mymap.end() || mymap[num[left]] != num[right]) {
        return false;
      }
    }
    return true;
  }
};
