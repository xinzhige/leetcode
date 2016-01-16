// space: O(n)
class Solution {
public:
    int minArray(vector<int> &arr) {
        int min = INT_MAX;
        for (int i = 0; i < arr.size(); ++i) {
            if (min > arr[i]) {
                min = arr[i];
            }
        }
        return min;
    }
    int minimumTotal(vector<vector<int> > &triangle) {
        int triangle_size = triangle.size();
        vector<int> arr;
        if (triangle_size > 0 && triangle[0].size() > 0) {
            arr.push_back(triangle[0][0]);
        }
        for (int i = 1; i < triangle_size; ++i) {
            vector<int> curr = arr;
            arr.push_back(0);
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    arr[j] = curr[j] + triangle[i][j];
                } else if (j == triangle[i].size()-1) {
                    arr[j] = curr[j-1] + triangle[i][j];
                } else {
                    int left = curr[j-1] + triangle[i][j];
                    int right = curr[j] + triangle[i][j];
                    arr[j] = min(left, right);
                }
            }
        }
        int result = 0;
        result = minArray(arr);
        return result;
    }
};

// space: O(1)
class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    for (int i = triangle.size() - 2; i >= 0; --i) {
      for (int j = 0; j < i + 1; ++j) {
	triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
      }
    }
    return triangle[0][0];
  }
};
