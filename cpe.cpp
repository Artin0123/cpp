#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  // count代表輸入的數量，
  int count = 0, len = 0;
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
      if (name[i] == ' ' && len != 0) {
        // 比較是否有重複，j代表之前的國家
        bool repeat = false;
        for (int j = 0; j < country.size(); j++) {
          if (country[j].compare(name.substr(len, i)) == 0) {
            countrycount[j]++;
            repeat = true;
            break;
          }
        }
        if (repeat == false) {
          country.push_back(name.substr(len, i));
          countrycount.push_back(1);
          break;
        }
      }
    }
  }
  for (int i = 0; i < country.size(); i++) {
    for (int j = i + 1; j < country.size(); j++) {
      if (int(country[j][0]) < int(country[i][0])) {
        swap(country[i], country[j]);
        swap(countrycount[i], countrycount[j]);
      }
    }
  }
  for (int i = 0; i < country.size(); i++) {
    cout << country[i] << " " << countrycount[i] << endl;
  }
}