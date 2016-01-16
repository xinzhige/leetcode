class Solution {
public:
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;
    vector<int> temp;
    if (num.size() == 0) {
      result.push_back(temp);
      return result; 
    }
    int first_number = num.at(0);
    vector<int> remainder = num;
    remainder.erase(remainder.begin());
    vector<vector<int> > next_permutation = permute(remainder);
    for (int i = 0; i < next_permutation.size(); i++) {
      for (int j = 0; j <= next_permutation[i].size(); j++) {
	temp = next_permutation[i];
	temp.insert(temp.begin()+j, first_number);
	result.push_back(temp);
      }
    }
    return result;
  }
};
