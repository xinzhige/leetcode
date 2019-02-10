class HitCounter {
public:
  /** Initialize your data structure here. */
  HitCounter() {
    time.resize(300);
    hits.resize(300);
  }

  /** Record a hit.
      @param timestamp - The current timestamp (in seconds granularity). */
  void hit(int timestamp) {
    int index = timestamp % 300;
    if (time[index] != timestamp) {
      time[index] = timestamp;
      hits[index] = 1;
    } else {
      hits[index] += 1;
    }
  }

  /** Return the number of hits in the past 5 minutes.
      @param timestamp - The current timestamp (in seconds granularity). */
  int getHits(int timestamp) {
    int total = 0;
    for (int i = 0; i < 300; ++i) {
      if (timestamp - time[i] < 300) {
        total += hits[i];
      }
    }
    return total;
  }

private:
  vector<int> time;  // current time
  vector<int> hits;  // number of hits on current time index
};
