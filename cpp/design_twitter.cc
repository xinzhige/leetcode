class Twitter {
public:
  /** Initialize your data structure here. */
  Twitter() {
    time = 0;
  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    follow(userId, userId);
    tweets[userId].emplace_back(time++, tweetId);
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (auto it = friends[userId].begin(); it != friends[userId].end(); ++it) {
      for (auto a = tweets[*it].begin(); a != tweets[*it].end(); ++a) {
        q.push(*a);
        if (q.size() > 10) {
          q.pop();
        }
      }
    }
    for (; !q.empty(); q.pop()) {
      result.emplace_back(q.top().second);
    }
    reverse(result.begin(), result.end());
    return result;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    friends[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    if (followerId != followeeId) {
      friends[followerId].erase(followeeId);
    }
  }

private:
  int time;
  unordered_map<int, unordered_set<int>> friends;
  unordered_map<int, vector<pair<int, int>>> tweets;
};
