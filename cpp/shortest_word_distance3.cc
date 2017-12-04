class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1;
        int index2 = -1;
        int dist = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                if (word1 == word2 && index1 != -1) {
                    dist = min(dis, i - index1);
                } 
                index1 = i;
            }
            if (words[i] == word2) {
                index2 = i; 
            }
            if (index1 != -1 && index2 != -1 && word1 != word2) {
                dist = min(dist, abs(index1 - index2)); 
            }
        }
        return dist;
    }
};
