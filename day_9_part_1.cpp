#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  vector<pair<int, int>> p;
  while (cin >> s) {
    int cp = s.find(',');
    int a = stoi(s.substr(0, cp));
    int b = stoi(s.substr(cp + 1));
    p.push_back({a, b});
  }
  int n = p.size();
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      ans = max(ans, (long long) abs(p[i].first - p[j].first + 1) * abs(p[i].second - p[j].second + 1));
    }
  }
  cout << ans;
  return 0;
}