#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  int out = 0;
  while (getline(cin, s)) {
    int n = s.size();
    vector<vector<int>> a;
    string in = s.substr(1, s.find(']') - 1);
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        vector<int> b;
        string num = "";
        for (int j = i + 1; s[j] != ')'; j++) {
          if (s[j] == ',') {
            b.push_back(stoi(num));
            num.clear();
          } else {
            num.push_back(s[j]);
          }
        }
        b.push_back(stoi(num));
        a.push_back(b);
      }
    }
    int m = a.size();
    int k = in.size();
    vector<int> target(k, 0);
    for (int i = 0; i < k; i++) {
      if (in[i] == '#') {
        target[i] = 1;
      }
    }
    auto get = [](long long x) {
      int bit = 0;
      while (x) {
        bit += (x & 1);
        x /= 2;
      }
      return bit;
    };
    int mx = get((1LL << m) - 1);
    for (long long i = 0; i < (1LL << m); i++) {
      vector<int> ans(k, 0); 
      for (long long bit = 0; bit < 13; bit++) {
        if ((1LL << bit) & i) {
          for (int j = 0; j < (int) a[bit].size(); j++) {
            ans[a[bit][j]] ^= 1;
          }
        }
      }
      if (target == ans) {
        mx = min(mx, get(i));
      }
    }
    out += mx;
  }
  cout << out;
  return 0;
}