class Solution {
public:
  int minMutation(string start, string end, vector<string>& bank) {
    unordered_map<string, int> pathDepth;
    unordered_map<string, bool> geneBank;
    for (const auto &g : bank) {
      if (geneBank.count(g) == 0) {
        geneBank[g] = true;
      }
    }
    queue<string> q;
    q.emplace(start);
    pathDepth[start] = 1;
    while (!q.empty()) {
      string currGene = q.front();
      q.pop();
      for (int i = 0; i < currGene.size(); ++i) {
        string newGene = currGene;
        for (const auto &ch : "ACGT") {
          newGene[i] = ch;
          if (geneBank.count(newGene) > 0) {
            if (newGene == end) {
              return pathDepth[currGene];
            }
            if (pathDepth.count(newGene) == 0) {
              q.emplace(newGene);
              pathDepth[newGene] = pathDepth[currGene] + 1;
            }
          }
        }
      }
    }
    return -1;
  }
};
