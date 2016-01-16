// recursive method
class Solution {
public:
  int numTrees(int n) {
    return numTrees(1,n);
  }
  
  int numTrees(int start, int end) {
    if (start >= end) {
      return 1;
    }  
    int total_num = 0;
    for (int i = start; i <= end; ++i) {
      total_num += numTrees(start,i-1)*numTrees(i+1,end);
    }
    return total_num;
  }
};

// iterative method
class Solution {
public:
  int numTrees(int n) {  
    vector<int> count(n+1, 0);  
    count[0] =1;  
    count[1] =1;  
    for(int i = 2; i <= n; ++i) {
	for(int j = 0; j < i; ++j) {  
	    count[i] += count[j]*count[i-j-1];   
	}  
    }  
    return count[n];  
  }  
};

// fast method
class Solution {
public:
  int numTrees(int n) {  
    int c = 1;
    for (int i = 2; i <= n; i++) {
      c = 2*(2*i-1)*c/(i+1);
    }
    return c;
  }
};
