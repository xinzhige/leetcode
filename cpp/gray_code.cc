/* method 1, n gray code is the set of n-1 gray code and the set of the addition of 1<<n to its reverse order.


000   =  00
001      01
011      11
010      10
110      100+10
111      100+11
101      100+01
100      100+00


 */

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> result;      
    result.push_back(0);  
    for(int i = 0; i< n; ++i) { 
      int highest_bit = 1<<i;  
      int curr_len = result.size();  
      for(int j = curr_len-1; j >= 0; --j) { 
	result.push_back(highest_bit + result[j]);  
      }  
    }  
    return result; 
  }
};

// method 2 by formular
class Solution {
public:
  vector<int> grayCode(int n) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    vector<int> result;
    int count = 1 << n;
    for(int i = 0 ; i < count; ++i) {
      int temp = i ^ (i>>1);
      result.push_back(temp);
    }
    return result;
  }
};
