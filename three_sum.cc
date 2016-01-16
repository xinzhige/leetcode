class Solution {  
public:  
  vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int>> result;
    if (num.size() < 3) {
      return result;
    }
    sort(num.begin(), num.end());
    const int target = 0;
    auto last = num.end();
    for (auto a = num.begin(); a < last-2; ++a) {
      if(a != num.begin() && *a == *(a-1)) {
	continue;  
      }
      auto b = next(a);
      auto c = prev(last);
      while (b < c) {
	if (*a + *b + *c < target) {
	  ++b;
	} else if (*a + *b + *c > target) {
	  --c;
	} else {
	  result.push_back({ *a, *b, *c });
	  ++b;
	  --c;
	} 
      }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result; 
  }  
};
