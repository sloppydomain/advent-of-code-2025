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
  while (true) {
    vector<string> new_g = g;
    int cur = 0;
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
          if (cnt < 4) {
            new_g[x][y] = 'x';
            cur++;
          }
        }
      }
    }
    if (cur == 0) break;
    swap(new_g, g);
    ans += cur;
  }
  cout << ans;
  return 0;
}

/*
assuming if in every iter 1 roll of paper is removed
then total n * m rolls are removed in O(n * m)
assuming n * m <= 1e6 always
*/