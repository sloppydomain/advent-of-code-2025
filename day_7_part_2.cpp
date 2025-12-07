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
  vector<vector<long long>> dp(n, vector<long long>(m));
  for (int i = start + 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i - 1][j] == 'S') {
        beam[i][j] = true;
        dp[i][j] = 1;
      } else if (beam[i - 1][j]) {
        if (g[i][j] == '^') {
          if (j - 1 >= 0 && g[i][j - 1] == '.') {
            beam[i][j - 1] = true;
            dp[i][j - 1] += dp[i - 1][j];
          }
          if (j + 1 < m && g[i][j + 1] == '.') {
            beam[i][j + 1] = true;
            dp[i][j + 1] += dp[i - 1][j];
          }
        } else {
          beam[i][j] = true;
          dp[i][j] += dp[i - 1][j];
        }
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j < m; ++j) ans += dp[n - 1][j];
  cout << ans;
  return 0;
}