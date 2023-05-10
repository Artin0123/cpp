#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  // count代表輸入的數量，
  int count = 0, len = 0, start = 0;
  // country代表各個國家名稱
  vector<string> country;
  // countrycount代表各個國家數量
  vector<int> countrycount;
  // name代表輸入的名稱
  string name;
  cin >> count;
  // k代表當下的國家
  for (int k = 0; k <= count; k++) {
    getline(cin, name);
    if (name.length() == 0) {
      continue;
    }
    for (int i = 0; i < name.length(); i++) {
      if (name[i] != ' ') {
        len++;
      }
      if (name[i] == ' ' && len == 0) {
        start++;
      }
      if (name[i] == ' ' && len != 0) {
        // 比較是否有重複，j代表之前的國家
        bool repeat = false;
        for (int j = 0; j < country.size(); j++) {
          if (country[j].compare(name.substr(start, len)) == 0) {
            countrycount[j]++;
            repeat = true;
            len = 0;
            start = 0;
          }
        }
        if (repeat == false) {
          country.push_back(name.substr(start, len));
          countrycount.push_back(1);
          len = 0;
          start = 0;
          break;
        }
        break;
      }
    }
  }
  for (int i = 0; i < country.size() - 1; i++) {
    for (int j = 0; j < country.size() - 1 - i; j++) {
      if (country[j] > country[j + 1]) {
        swap(country[j], country[j + 1]);
        swap(countrycount[j], countrycount[j + 1]);
      }
    }
  }
  for (int i = 0; i < country.size(); i++) {
    cout << country[i] << " " << countrycount[i] << endl;
  }
}