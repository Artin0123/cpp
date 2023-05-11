#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool cmp(pair<char, int> a, pair<char, int> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second > b.second;
}
int main() {
  int n;
  cin >> n;
  cin.ignore();
  map<char, int> count;
  for (int i = 0; i < n; i++) {
    string s;
    getline(cin, s);
    for (int j = 0; j < s.length(); j++) {
      if (int(s[j]) >= 65 && int(s[j]) <= 90) {
        count[int(s[j])]++;
      }
      if (int(s[j]) >= 97 && int(s[j]) <= 122) {
        count[int(s[j]) - 32]++;
      }
    }
  }
  vector<pair<char, int>> v(count.begin(), count.end());
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i <= v.size(); i++) {
    if (v[i].second != 0) {
      cout << v[i].first << " " << v[i].second << endl;
    }
  }
}