#include <iostream>
#include <string>

using namespace std;

char FirstNonrepeatedChar(string s) {
  int s_len = s.size();
  if (s_len == 0) {
    return '\0';
  }
  const int kNumChars = 256;
  int appeared[kNumChars] = { 0 };
  for (int i = 0; i < s_len; ++i) {
    int curr_index = (int)s[i];
    ++appeared[curr_index];
  }
  for (int i = 0; i < s_len; ++i) {
    int curr_index = (int)s[i];
    if(appeared[curr_index] == 1) {
      return s[i];
    }
  }
  return '\0';
}

int main() {
  string s = "teeter";
  char c = FirstNonrepeatedChar(s);
  cout<<s<<endl;
  cout<<c<<endl;
  return 0;
}
