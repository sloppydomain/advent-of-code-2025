#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<string> g;
  string s;
  while (cin >> s) {
    g.push_back(s);
  }
  int n = g.size(), m = g[0].size();
  vector<vector<bool>> beam(n, vector<bool>(m, false));
  int start = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'S') {
        start = i;
        break;
      }
    }
    if (start != -1) break;
  }
  int ans = 0;
  for (int i = start + 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i - 1][j] == 'S') {
        beam[i][j] = true;
      } else if (beam[i - 1][j]) {
        if (g[i][j] == '^') {
          bool ok = false;
          if (j - 1 >= 0 && g[i][j - 1] == '.') {
            beam[i][j - 1] = true;
            ok = true;
          }
          if (j + 1 < m && g[i][j + 1] == '.') {
            beam[i][j + 1] = true;
            ok = true;
          }
          ans += ok;
        } else {
          beam[i][j] = true;
        }
      }
    }
  }
  cout << ans;
  return 0;
}