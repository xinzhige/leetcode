class Logger {
public:
  /** Initialize your data structure here. */
  Logger() {

  }

  /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
      If this method returns false, the message will not be printed.
      The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    if (timestamp < timer[message]) {
      return false;
    }
    timer[message] = timestamp + 10;
    return true;
  }

private:
  unordered_map<string, int> timer;
};
