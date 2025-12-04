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
  vector<int> dx = {-1, -1, 1, 1, 0, 0, -1, 1};
  vector<int> dy = {-1, 1, -1, 1, -1, 1, 0, 0};
  int ans = 0;
  vector<string> new_g = g;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (g[x][y] == '@') {
        int cnt = 0;
        for (int k = 0; k < 8; k++) {
          int nx = x + dx[k], ny = y + dy[k];
          if (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] == '@') {
            cnt++;
          }
        }
        ans += (cnt < 4);
      }
    }
  }
  cout << ans;
  return 0;
}