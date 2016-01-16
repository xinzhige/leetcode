class Solution {
public:
  int minDistance(string word1, string word2) {
    int matrix[word1.size()+1][word2.size()+1];
    for (int i = 0; i <= word1.size(); ++i) {
      matrix[i][0] = i;
    }
    for (int j = 0; j <= word2.size(); ++j) {
      matrix[0][j] = j;
    }
    for (int i = 1; i <= word1.size(); ++i) {
      for (int j = 1; j <= word2.size(); ++j) {
	if (word1[i-1] == word2[j-1]) {
	  matrix[i][j] = matrix[i-1][j-1];
	} else {
	  int curr_min = min(matrix[i-1][j], matrix[i][j-1]);
	  matrix[i][j] = 1 + min(matrix[i-1][j-1], curr_min);
	}
      }
        }
    return matrix[word1.size()][word2.size()];
  }
};
