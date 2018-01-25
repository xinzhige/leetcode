class Solution {
public:
  int findPeakElement(const vector<int> &num) {
    int N = num.size();
	int begin = 0;
	int end = N - 1;
	int mid = 0;
	while (begin <= end) {
      mid = begin + (end - begin) / 2;
	  if ((mid == 0 || num[mid] > num[mid - 1]) &&
		  (mid == N - 1 || num[mid] > num[mid + 1])) {
	    return mid;		  
	  } else if (mid > 0 && num[mid] < num[mid - 1]) {
	    end = mid - 1;		  
	  } else {
	    begin = mid + 1;		  
	  }	
	}		 
	return mid; 
  }
};
