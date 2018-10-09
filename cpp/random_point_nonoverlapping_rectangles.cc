class Solution {
public:
  Solution(vector<vector<int>> rects) {
    rectangles = rects;
    for (const auto& rect : rects) {
      int width = rect[2] - rect[0] + 1;
      int height = rect[3] - rect[1] + 1;
      int area = width * height;
      sum += area;
      presums.push_back(sum);
    }
  }

  vector<int> pick() {
    int len = presums.size();
    int r = (rand() % sum) + 1;
    int low = 0;
    int high = len - 1;
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (presums[mid] < r) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    auto rect = rectangles[low];
    int width = rect[2] - rect[0] + 1;
    int height = rect[3] - rect[1] + 1;
    int area = width * height;
    int x = rect[0] + (r - presums[low] + area - 1) % width;
    int y = rect[1] + (r - presums[low] + area - 1) / width;
    return {x, y};
  }

private:
  vector<vector<int>> rectangles;
  vector<int> presums;
  int sum = 0;
};
