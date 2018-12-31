class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    set<string> unique_emails;
    for (const auto &email : emails) {
      int pos = email.find('@');
      string local = email.substr(0, pos);
      string domain = email.substr(pos + 1);
      string tmp_local = local.substr(0, local.find('+'));
      string new_local = "";
      for (const char &c : tmp_local) {
        if (c != '.') {
          new_local.push_back(c);
        }
      }
      unique_emails.insert(new_local + domain);
    }
    return unique_emails.size();
  }
};
