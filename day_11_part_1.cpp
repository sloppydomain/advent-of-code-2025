#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  map<string, vector<string>> edges;
  string s;
  while (getline(cin, s)) {
    int p = s.find(':');
    string u = s.substr(0, p);
    int n = s.size();
    string cur = "";
    vector<string> v;
    for (int i = p + 2; i <= n; i++) {
      if (i == n || s[i] == ' ') {
        v.push_back(cur);
        cur.clear();
      } else {
        cur.push_back(s[i]);
      }
    }
    edges[u] = v;
  }
  unordered_set<string> vis;
  auto dfs = [&](auto &&self, string u) {
    if (u == "out") return 1;
    int tot = 0;
    vis.insert(u);
    for (string &v : edges[u]) {
      if (vis.count(v) == 0) {
        tot += self(self, v);
      }
    }
    vis.erase(u);
    return tot;
  };
  cout << dfs(dfs, "you");
  return 0;
}
