class Solution {
public:
  string getHint(string secret, string guess) {
    int bulls = 0;
    int cows = 0;
    vector<int> count(10, 0);
    for (int i = 0; i < secret.size(); ++i) {
      if (secret[i] == guess[i]) {
        bulls += 1;
      } else {
        int s = secret[i] - '0';
        int g = guess[i] - '0';
        if (count[s] < 0) {
          cows += 1;
        }
        if (count[g] > 0) {
          cows += 1;
        }
        count[s]++;
        count[g]--;
      }
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};
