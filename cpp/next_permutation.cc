class Solution {
public:
  void nextPermutation(vector<int> &num) {
    int pivot = -1;
    int change = 0;
    //step1
    for (int i = 0; i < num.size() - 1; ++i) {
      if (num[i] < num[i+1]) {
	pivot = i;
      }
    }
    if (pivot == -1) {
      sort(num.begin(), num.end());
      return;
    }
    //step2
    for (int i = 0; i < num.size(); ++i){
      if (num[i] > num[pivot]){
	change = i;
      }
    }
    //step3    
    swap(num[change], num[pivot]);
    //step4
    reverse(num.begin()+pivot+1, num.end());
  }
};
