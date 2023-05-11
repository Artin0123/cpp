#include <iostream>
using namespace std;
int main() {
  long long n = 0;
  int sum = 0;
  while (cin >> n && n != 0) {
    int i = n;
    if (i < 10) {
      sum = i;
    }
    for (; i >= 10;) {
      sum = 0;
      for (; i > 0;) {
        sum += i % 10;
        i = i / 10;
      }
      i = sum;
    }
    cout << sum << endl;
  }
}