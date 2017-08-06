class Solution {
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> result, height;
    for (auto &b : buildings) {
      height.push_back(make_pair(b[0], -b[2])); 
      height.push_back(make_pair(b[1], b[2])); 
    }
    sort(height.begin(), height.end());
    multiset<int> myheap;
    myheap.insert(0);
    int prev = 0;
    int curr = 0;
    for (auto &h : height) {
      if (h.second < 0) {
        myheap.insert(abs(h.second)); 
      } else {
        myheap.erase(myheap.find(h.second)); 
      } 
      auto curr = *myheap.rbegin();
      if (curr != prev) {
        result.push_back(make_pair(h.first, curr)); 
        prev = curr;
      }
    }
    return result;
  }
}
