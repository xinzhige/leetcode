// method 1: bit manipulation, count the digits appear no three times
class Solution {
public:
  int singleNumber(int A[], int n) {
    int count[32];
    int result = 0;
    for (int i = 0;i < 32;++i) {
      count[i] = 0;
      for (int j = 0;j < n;++j) {
	if ((A[j] >> i) & 1) {
	  count[i] = (count[i] + 1) % 3; // the number of certain digit for the number of three occurances must be times of 3 so we use % to filter them
	}
      }
      result |= (count[i] << i);
    }
    return result;
  }
};

// more efficiently but not esay to understand
class Solution {
public:
  int singleNumber(int A[], int n) {
    int ones = 0, twos = 0, xthrees = 0;
    for(int i = 0; i < n; ++i) {
      twos |= (ones & A[i]); // store the digits appeared twice
      ones ^= A[i]; // store the digits appeared once
      xthrees = ~(ones & twos); // store the digits appeared 3 times
      ones &= xthrees;  // let the digits appeared 3 times be 0
      twos &= xthrees;
    }   
    return ones;
  }
};

