class Solution {
public:
  string validIPAddress(string IP) {
    if (IP.find('.') != string::npos) {
      return checkIPv4(IP);
    }
    if (IP.find(':') != string::npos) {
      return checkIPv6(IP);
    }
    return "Neither";
  }

  string checkIPv4(string IP) {
    istringstream is(IP);
    string t = "";
    int count = 0;
    while (getline(is, t, '.')) {
      ++count;
      if (count > 4 || t.empty() || (t.size() > 1 && t[0] == '0') ||
          t.size() > 3) {
        return "Neither";
      }
      for (auto &ch : t) {
        if (ch < '0' || ch > '9') {
          return "Neither";
        }
      }
      int num = stoi(t);
      if (num < 0 || num > 255) {
        return "Neither";
      }
    }
    if (count == 4 && IP.back() != '.') {
      return "IPv4";
    }
    return "Neither";
  }

  string checkIPv6(string IP) {
    istringstream is(IP);
    string t = "";
    int count = 0;
    while (getline(is, t, ':')) {
      ++count;
      if (count > 8 || t.empty() || t.size() > 4) {
        return "Neither";
      }
      for (auto &ch : t) {
        if ((ch < '0' || ch > '9') && (ch < 'a' || ch > 'f') &&
            (ch < 'A' || ch > 'F')) {
          return "Neither";
        }
      }
    }
    if (count == 8 && IP.back() != ':') {
      return "IPv6";
    }
    return "Neither";
  }
};
