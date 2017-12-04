class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> mymap;
    for (int i = 0; i < list1.size(); ++i) {
      mymap[list1[i]] = i;
    }
    int curr_max = INT_MAX;
    vector<string> result;
    for (int i = 0; i < list2.size(); ++i) {
      if (mymap.find(list2[i]) != mymap.end()) {
        int curr = i + mymap[list2[i]];
        if (curr < curr_max) {
          result.clear();
          curr_max = curr;
          result.push_back(list2[i]);
        } else if (curr == curr_max) {
          result.push_back(list2[i]);
        }
      }
    }
    return result;
  }
};
