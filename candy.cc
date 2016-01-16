class Solution {
public:
  int candy(vector<int> &ratings) {
    int number_children = ratings.size();
    if (number_children == 0) {
      return 0;
    }
    vector<int> count(number_children, 1);
    int sum = 0;
    for (int i = 1; i < number_children; ++i) {
      if (ratings[i] > ratings[i-1]) {
	count[i] = count[i-1] + 1;
      }
    }
    for (int i = number_children - 1; i >= 1; --i) {
      sum += count[i];
      if (ratings[i-1] > ratings[i] && count[i-1] <= count[i]) {
	count[i-1] = count[i] + 1;
      }
    }
    sum += count[0];
    return sum;
  }
};
