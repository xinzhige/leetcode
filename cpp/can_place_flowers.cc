class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int m= flowerbed.size();
    int num = 0;
    for (int i = 0; i < m; ++i) {
      if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) &&
          (i == m - 1 || flowerbed[i+1] == 0)) {
        flowerbed[i] = 0;
        ++i;
        ++num;
      }
      if (num >= n) {
        return true;
      }
    }
    return false;
  }
};
