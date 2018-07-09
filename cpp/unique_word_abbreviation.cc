class ValidWordAbbr {
public:
  ValidWordAbbr(vector<string> dictionary) {
    for (const auto &d : dictionary) {
      auto key = convert(d);
      if (mymap.count(key) == 0) {
        mymap[key] = unordered_set<string>();
      }
      mymap[key].insert(d);
    }
  }

  bool isUnique(string word) {
    auto key = convert(word);
    if (mymap.count(key) == 0) {
      return true;
    } else if (mymap[key].count(word) > 0 && mymap[key].size() == 1) {
      return true;
    } else {
      return false;
    }
  }

  string convert(string word) {
    int n = word.size();
    if (n < 3) {
      return word;
    } else {
      return word[0] + to_string(len-2) + word[len -1];
    }
  }

private:
  unordered_map<string, unordered_set<string>> mymap;
};
