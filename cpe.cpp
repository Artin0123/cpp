#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  // count代表輸入的數量，
  int count = 0;
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
    for (int i = 0; i < name.length(); i++) {
      // 偵測到第一個空白，代表國家名稱結束
      if (name[i] == ' ') {
        if (k == 1) {
          country.push_back(name.substr(0, i));
          countrycount.push_back(1);
          break;
        }
        // 比較是否有重複，j代表之前的國家
        bool repeat = false;
        for (int j = 0; j < k; j++) {
          if (country[j].compare(name.substr(0, i)) == 0) {
            countrycount[j]++;
            repeat = true;
            break;
          }
        }
        if (repeat == false) {
          country.push_back(name.substr(0, i));
          countrycount.push_back(1);
        }
        break;
      }
    }
  }
  // for (int i = 0; i < country.size(); i++) {
  //   if(country[i][1])
  // }
  for (int i = 0; i < country.size(); i++) {
    cout << country[i] << " " << countrycount[i] << endl;
  }
}