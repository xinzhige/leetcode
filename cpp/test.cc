#include <iostream>

using namespace std;

int main(int args, char *argv[]) {
  int x = 8;
  int y = 3;
  int z = (x %= y);
  cout<<z<<endl;
  cout<<x<<endl;
  return 0;
}
