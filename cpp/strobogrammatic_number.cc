class Solution {
public:
  bool isStrobogrammatic(string num) {
    unordered_map<char, char> mymap{{'0', '0'}, {'1', '1'}, {'6', '9'},
                                    {'8', '8'}, {'9', '6'}};
    for (int left = 0, right = num.size() - 1; left <= right;
         left++, right--) {
      if (mymap.count(num[left]) == 0 || mymap[num[left]] != num[right]) {
        return false;
      }
    }
    return true;
  }
};
