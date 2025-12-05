#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  vector<pair<long long, long long>> ip;
  vector<long long> q;
  while (cin >> s) {
    size_t pos = s.find('-');
    if (pos == string::npos) {
      long long x = stoll(s);
      q.push_back(x);
    } else {
      long long L = stoll(s.substr(0, pos));
      long long R = stoll(s.substr(pos + 1));
      ip.push_back({L, R});
    }
  }
  long long n = ip.size();
  sort(ip.begin(), ip.end());
  vector<pair<long long, long long>> p;
  p.push_back({ip[0].first, ip[0].second});
  for (long long i = 1; i < n; i++) {
    pair<long long, long long> back = p.back();
    long long new_x = ip[i].first, new_y = ip[i].second;
    long long y = back.second;
    if (new_x > y) {
      p.push_back({new_x, new_y});
    } else if (new_y > y) {
      p.back().second = new_y;
    }
  }
  long long ans = 0;
  for (auto x : q) {
    auto it = upper_bound(
      p.begin(), p.end(),
      x,
      [](long long v, const pair<long long, long long>& in) {
        return v < in.first;
      }
    );
    if (it != p.begin()) {
      it--;
      auto [L, R] = *it;
      if (L <= x && x <= R) ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}