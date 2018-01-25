// Space: O(n)
class Solution {
public:
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;
    vector<int> tmp;
    dfs(num, tmp, result);
    return result;
  }

private:
  bool contains(vector<int> &a, int x) {
    for (auto &i : a) {
      if (i == x) {
        return true;
      }
    }
    return false;
  }

  void dfs(vector<int>& nums, vector<int> tmp, vector<vector<int>> &result) {
    if (tmp.size() == nums.size()) {
      result.emplace_back(tmp);
    } else {
      for (int i = 0; i < nums.size(); ++i) {
        if (!contains(tmp, nums[i])) {
          tmp.emplace_back(nums[i]);
          dfs(nums, tmp, result);
          tmp.pop_back();
        }
      }
    }
  }
};

// Space: O(1)
class Solution {
public:
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;
    dfs(num, 0, result);
    return result;
  }
  void dfs(vector<int> &num, int pos, vector<vector<int>> &result) {
    if(pos == num.size()) {
      result.push_back(num);
    } else {
      for(int i = pos; i < num.size(); ++i) {
        swap(num[i], num[pos]);
        dfs(num, pos+1, result);
        swap(num[i], num[pos]);
      }
    }
  }
};
